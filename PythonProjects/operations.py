#per5A-operations.py

#Performance Lab 5A
#Robert John Graham III
#September 12 201i8

import calcinput

#Default print statement for the overall loop, letting the user know
#the correct input format
def print_loop():
    print("Available operators are !,F,^,/,*,+,-")
    print("This is also the order of precendence for the operators")
    print("Use of () is encouraged, all non-numeric and non-operator"),
    print("characters will be removed.")

#Function that processes the user input and then converts the input
#into a postfix expression that will return a result
def operations_loop():
    operator_stack = calcinput.expression_input()
    #This loop will convert the string provided to a postfix
    #expression
    for item in operator_stack:
        #If item is a number, then add to postfix
        if item.isdigit():
            postfix_stack.append(item)
        #If item is (, then put it on stack
        if item == "(":
            transform_stack.append(item)
        if item == ")":
            #If item is ), pop stack into postfix until ( is hit
            while transform_stack[-1] != "(":
                postfix_stack.append(transform_stack.pop())
            #Remove ( from stack
            transform_stack.pop()
        #If item is an operator
        if item in operator_list[2::]:
            #Pop stack into postfix until stack is empty
            #OR hit a ( OR precedence of operator is greater than
            #the next operator on stack
            while (len(transform_stack) > 0
            and transform_stack[-1] != "("
            and operator_list.index(item)
            >= operator_list.index(transform_stack[0])):
                postfix_stack.append(transform_stack.pop(0))
            transform_stack.append(item)
    #If the expression provided has a wrong number of paratheses provided
    #the user will be informed
    if transform_stack[-1] == "(":
        print("UNBALANCED PARENTHESES")
    else:
        #Postfix expression is balanced, so the stack is evaluated
        postfix_stack.extend(reversed(transform_stack))
        transform_stack = []
        #Evaluation of items in postfix expression
        for item in postfix_stack:
            #if item is a number, add to stack
            if item.isdigit():
                transform_stack.append(item)
            #if item is an operator, perform action on operands
            #and then put result back into stack
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
        #Last item on the stack should be the result
        print(transform_stack.pop())

