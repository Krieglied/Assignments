#Performance Lab 4A - Lambda
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

print("CALCULATOR")
print_loop()
#Further line will be added here for the algorithms available
#Default variables and operators
operator_list = ["+", "-", "/", "*","^", "F", "!"]
first = 0
second = 0
operator = ""
while True:
    input_values = raw_input().split()
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

#This section creates the functions inline
#Lambdas
print("Lamda output")
if operator == "+":
    x = lambda a,b: a + b
if operator == "-":
    x = lambda a,b: a - b
if operator == "/":
    x = lambda a,b: a / b
if operator == "*":
    x = lambda a,b: a * b
if operator == "^":
    x = lambda a,b: a ** b
if operator == "F":
    x = lambda n:reduce(lambda x,n: [x[1], x[0] + x[1]], range(n), [0,1])[0]
if operator == "!":
    fact = lambda x: 1 if x == 0 else x * fact(x - 1)
if operator in ["+", "-", "/", "*", "^"]:
    print("The result of {} {} {} is {}").format(
            first, operator, second, x(first, second))
if operator is "F":
    print("The fibonacci number at position {} is {}").format(    
            first, x(first))
if operator is "!":
    print("{} {} is {}").format(
            first, operator, fact(first))
