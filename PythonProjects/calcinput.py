#per5A-input.py

#Performance Lab 5A
#Robert John Graham III
#September 12 2018

def expression_input():
    input_line = raw_input("Please input a math line\n").rstrip()
    operator_list = ["(", ")", "!", "F", "^", "/", "*", "+", "-"]
    operator_stack = []
    transform_stack = []
    postfix_stack = []
    number = ""
    #This will remove any non-numeric and non-operator characters
    #from the user string
    for i in xrange(len(input_line)):
        #If the digit is an operator, add that as a separate item
        #to the list
        if input_line[i] in operator_list:
            #If the number variable has anything in it, then that
            #number needs to be added to the stack first
            if number != "":
                operator_stack.append(number)
                number = ""
            #Operator is added to the stack
            operator_stack.append(input_line[i])
        #If the digit is a digit, add to the number variable
        elif input_line[i].isdigit():
            number += input_line[i]
        #If digit is a space, then if there were any numbers in
        #number variable, number needs to be added to the stack
        elif input_line[i] == " ":
            if number != "":
                operator_stack.append(number)
                number = ""
        #If this is the last digit and there is something in
        #number variable, number needs to be added to the stack
        if i == (len(input_line) - 1) and number != "":
            operator_stack.append(number)
    return operator_stack
