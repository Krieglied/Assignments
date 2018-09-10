#Performance Lab 3E
#Robert John Graham III
#September 7 2018

"""
    Write a file that prints out the first 100 numbers in the Fibonacci 
    sequence iteratively.  Revist this lab and create a Fibonacci 
    recursive function.
"""
import time
import sys
#Recursive function that outputs the final number in the fibonacci sequence
def rec_fibo(numbers, fibo_computed = {0:0, 1:1}):
    if numbers not in fibo_computed:
        fibo_computed[numbers] = rec_fibo(numbers -1, fibo_computed) + rec_fibo(numbers-2, fibo_computed)
    return fibo_computed[numbers]
sys.setrecursionlimit(5000)
#Numbers of fibonacci sequence to display
numbers = int(sys.argv[1])
first = 1
second = 1
current = 0
start = time.time()
print(first)
print(second)
#Displays numbers after the first two 1s in the sequence
for i in xrange(3, numbers+1):
    current = first + second
    first = second
    second = current
    print(current)
print("Iterative form takes {} seconds").format(time.time() - start)
#Handles the call to the function call
start = time.time()
print(rec_fibo(numbers))
print("Recursive form takes {} seconds").format(time.time() - start)
