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
    #print 'Fizz' * (i % 3 == 0) + 'Buzz' * (i % 5 == 0) or i
    print i if (i % 3 != 0 and i % 5 != 0) else ("FizzBuzz" if (i % 3 == 0 and i % 5 == 0) else ("Fizz" if (i % 3 == 0) else "Buzz"))
