#Performance Lab 4A - Functions
#Robert John Graham III
#September 10 2018

"""
    Create a fully functional calculator using BOTH functions and lambdas. 
    Create a user menu as well as a "screen" where the numbers and 
    operations take place. The calculator needs to have the following 
    functionality:

    Addition
    Subtraction
    Division
    Multiplication
    Power
    At least two math algorithms (One can be your Fibonacci)

"""
#Verifies the user input for the numbers, making sure they are of type
#int
def value_verify(value):
    try:
        capture = int(value)
    except ValueError:
        #Function will continue to run until a valid number is put in
        capture = raw_input("Please input an int: ")
        capture = value_verify(capture)
    return capture
#Default print statement for the overall loop, letting the user know
#the correct input format
def print_loop():
    print("Available operators are +,-,/,*,^,F,!")
    print("For +,-,/,*,^: the format is number operator number")
    print("For F, !: the format is number operator")
#Function that adds numbers
def add_numbers(first, second):
    return first + second
#Function that subtracts numbers
def sub_numbers(first, second):
    return first - second
#Function that multiplies numbers
def multiply_numbers(first, second):
    return first * second
#Function that divides numbers
def divide_numbers(first, second):
    return first / second
#Function that raises the first number by the power of the second
def expo_numbers(first, second):
    return first ** second
#Function that computes the fibonacci number at postion numbers
def fibonacci(numbers, computed = {0:0, 1:1}):
    if numbers not in computed:
        computed[numbers] = (fibonacci(numbers -1, computed) 
        + fibonacci(numbers-2, computed))
    return computed[numbers]
#Function that computes numbers!
def factorial(numbers):
    if numbers < 1:
        return 1
    else:
        return numbers * factorial(numbers - 1)
#This function handles the actual processing of numbers provided
def operations_loop(output):
    #Default variables and operators
    operator_list = ["+", "-", "/", "*","^", "F", "!"]
    first = 0
    second = 0
    operator = ""
    while True:
        #If the loop is a fresh one, then the inputs are processed
        #normally
        if output == 0:
            input_values = raw_input().split()
        #If the user is using a previous loop's result, then the 
        #result is presented, and stored to be used
        else:
            input_values = raw_input("{} ".format(output)).split()
            input_values.insert(0, output)
        #If too many entries are put in, or an invalid operator is received
        #The loop repeats and the user is prompted for input again
        if len(input_values) > 3 or input_values[1] not in operator_list:
            print_loop()
            continue
        if len(input_values) >= 2:
            #The values are assigned and checked into their variables
            first = value_verify(input_values[0])
            operator = input_values[1]
        #If the number of arguments is 3, then the second number
        #needs to be captured
        if len(input_values) == 3:
            second = value_verify(input_values[2])
        #If the number of arguments is 2 and the operator provided is 
        #either not F or !, then user needs to provide arguments again
        if ((len(input_values) == 2 ) and (operator is not "F"
            and operator is not "!" )):
            print("test")
            print("Incorrect values and operators.")
            print_loop()
            continue
        #For divison, if the second number is 0, then that is invalid
        #The user is prompted for a valid input
        if (operator == "/" and second == 0):
            print("This will cause division by 0.")
            print_loop()
            continue
        break
    #Once the user has given valid inputs, then the function output
    #will be printed
    #Functions
    print("Function output")
    if operator == "+":
        output = add_numbers(first,second)
        print("The result of {} {} {} is {}").format(
                first, operator, second, output)
    if operator == "-":
        output = sub_numbers(first,second)
        print("The result of {} {} {} is {}").format(
                first, operator, second, output)
    if operator == "/":
        output = divide_numbers(first, second)
        print("The result of {} {} {} is {}").format(
                first, operator, second, output)
    if operator == "*":
        output = multiply_numbers(first, second)
        print("The result of {} {} {} is {}").format(
                first, operator, second, output)
    if operator == "^":
        output = expo_numbers(first, second)
        print("The result of {} {} {} is {}").format(
                first, operator, second, output)
    if operator == "F":
        output = fibonacci(first)
        print("The fibonacci number at position {} is {}").format(
                first, output)
    if operator == "!":
        output = factorial(first)
        print("{} {} is {}").format(
                first, operator, output)
    #The result needs to be sent back, to be evaluated possibly
    #for the next loop
    return output


print("CALCULATOR")
result = 0
while True:
    print_loop()
    #Call to the processing loop
    result = operations_loop(result)
    user_choice = ""
    #Here the user is presented with the choice of using the result
    #for the next loop, starting a fresh computation loop, or exiting
    #the program
    while True:
        print("Do you wish to clear the calculator (CLR), continue to use"),
        print("the value just return (CON), or exit the program (EXIT)?")
        user_choice = raw_input("::: ")
        if user_choice.upper() in ["CLR", "CON", "EXIT"]:
            break
        else:
            print("Please select a valid choice.")
    if user_choice.upper() == "EXIT":
        break
    #If the user clears the result, it needs to be zeroed for the next loop
    if user_choice.upper() == "CLR":
        result = 0
