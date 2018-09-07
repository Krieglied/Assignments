#Performance Lab 3D
#Robert John Graham III
#September 7 2018

"""
    Write a program that prompts a user to input an integer and 
    calculates the factorial of that number using a while loop.
"""
#This function error checks to make that the grade input
#Is of int type.  The function will continue to run
#Until a value of the correct type is input
def read_input():
    capture = raw_input("Please input an integer: ")
    try:
        capture = int(capture)
    except ValueError:
       print "Please enter an int."
       capture = read_input()
    return capture

#Introduction loop asks user for a valid integer
print("Program will compute the factorial of the input.")
iteration = read_input()
factorial = 1
#Iteration is decremented and each decrement is multliplied 
#against factorial, which starts at one
while iteration > 0:
    factorial *= iteration
    iteration -= 1
print("The factorial of the input is {}").format(factorial)
