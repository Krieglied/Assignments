#Performance Lab 3F
#Robert John Graham III
#September 10 2018

"""
    Iterate through a loop 100 times... printing "Fizz" for any number 
    divisable by 3 and "Buzz" for any number divisable by 5. If the 
    number is divisable by both... print "FizzBuzz". All other 
    numbers... print the number.
"""
counter = 100
output = ""
#Numbers from 1 to 100 are evaluated
for i in range(1, counter + 1):
    #If the number is divisable by 3 or 5, then output will just be the number
    if i % 3 != 0 and i % 5 != 0:
        output = i
    #If the number is divisable by 3, output has Fizz at the beginning
    if i % 3 == 0:
        output = "Fizz"
    #If the number is divisable by 5, add Buzz to the output
    if i % 5 == 0:
        output += "Buzz"
    #Output is printed and then reset for the next loop
    print output
    output = ""
