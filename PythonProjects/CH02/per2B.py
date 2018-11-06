"""Python2 lab2b"""
print "==================================="

# TODO: Set x equal to 545, set y equal to 24
x,y = 545, 24

# TODO: Set binX equal to bin representation of x, 
# TODO: Set binY equal to bin representation of y
binX, binY = bin(x), bin(y)

print "{} is {} in binary. {} is {} in binary.".format(x, binX, y, binY)

print "Values before modification: x: {} and y: {}".format(x, y)


# TODO: manually flip the third bit in x, manually lfip the 1st bit in y
x,y = x^4, y^1

print "Values after modificaiton: x: {} and y: {}".format(x, y)

# NOTE: You may need to add additional re-asignments for the TODOs below
# TODO: sum of x and y as a hex value
# TODO: difference of x minus y as int
# TODO: product of x and y as octal
# TODO: x modulus 3 as int
# TODO: y squared as int
answer1,answer2,answer3,answer4 = hex(x+y),int(x-y),oct(x*y),bin(x/y)
answer5,answer6 = int(x%3),int(y**2)

print "1: {}\n2: {}\n3: {}\n4: {}\n5: {}\n6: {}\n \b===================================".format(answer1, answer2, answer3, answer4, answer5, answer6)

# TODO: Using prefixes and conversions:

## TODO: Set binA == 0011, set binB to 1001
binA,binB = 0b0011,0b1001
## TODO: binA AND binB, assign the value to binC
binC = binA & binB

## TODO: Set decA to decimal version of binA, set decB to decimal version of binB
decA,decB = int(binA),int(binB)

## TODO: Set binA to bin representation of binA, set binB to the bin representation of binB
binA,binB = bin(binA),bin(binB)

print "Results:\n-Decimal- A: {} B: {}\n-Binary- A: {} B: {}".format(decA, decB, binA, binB)
