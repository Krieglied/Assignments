#Performance Lab 4A - PEMDAS
#Robert John Graham III
#September 10 2018

"""
    Calculator that uses a stack with postfix notation to evaluate expressions
    Program allows for +,-,',*,! and also Fibonacci sequence substition
    which is represented by F
"""
input_line = raw_input("Please input a math line\n")
operator_list = ["(", ")", "!", "F", "^", "/", "*", "+", "-"]
operator_stack = []
transform_stack = []
postfix_stack = []
number = ""
for i in xrange(len(input_line)):
    if input_line[i] in operator_list:
        if number != "":
            operator_stack.append(number)
            number = ""
        operator_stack.append(input_line[i])
    elif input_line[i].isdigit():
        number += input_line[i]
    elif input_line[i] == " ":
        if number != "":
            operator_stack.append(number)
            number = ""
    if i == (len(input_line) - 1) and number != "":
        operator_stack.append(number)
for item in operator_stack:
    if item.isdigit():
        postfix_stack.append(item)
    if item == "(":
        transform_stack.append(item)
    if item == ")":
        while transform_stack[-1] != "(":
            postfix_stack.append(transform_stack.pop())
        transform_stack.pop()
    if item in operator_list[2::]:
        while len(transform_stack) > 0 and transform_stack[-1] != "(" and operator_list.index(item) >= operator_list.index(transform_stack[0]):
            postfix_stack.append(transform_stack.pop(0))
        transform_stack.append(item)
if transform_stack[-1] == "(":
    print("UNBALANCED PARENTHESES")
else:
    postfix_stack.extend(reversed(transform_stack))
    transform_stack = []
    for item in postfix_stack:
        if item.isdigit():
            transform_stack.append(item)
        if item in operator_list[2::]:
            first = int(transform_stack.pop())
            if item in operator_list[4::]:
                second = int(transform_stack.pop())
            result = 0
            if item is "+":
                result = first + second
            if item is "-":
                result = second - first
            if item is "*":
                result = first * second
            if item is "/":
                if first == 0:
                    print("DIVISION BY 0")
                    break
                else:
                    result = second / first
            if item is "^":
                result = second ** first
            if item is "!":
                fact = lambda x: 1 if x == 0 else x * fact(x - 1)
                result = fact(first)
            if item.upper() == "F":
                fibo = lambda n:reduce(lambda x,n: [x[1], x[0] + x[1]], range(n), [0,1])[0]
                result = fibo(first)
            transform_stack.append(result)
    print(transform_stack.pop())
