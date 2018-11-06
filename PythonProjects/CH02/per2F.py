#Performance Lab 2F
#Robert John Graham III
#September 5 2018

""" Write a program that will be able to check if two words (strings) 
    are anagrams.  An anagram is a word or phrase formed by 
    rearranging the letters of a different word or phrase
"""

#First user needs to be asked for the first string
string1 = raw_input("Please enter a string: ")
string2 = raw_input("Please enter another string: ")
#Variable to indicate whether the strings are anagrams
isAnagram = True
testString = string1
#Test to see if each character in string2 is in string1
for i in string2 :
    #Return an index if character found
    index = testString.find(i)
    #If index is -1, character not found and not an anagram
    if index == -1 :
        isAnagram = False
    #If found, then remove character from testString
    #So that repeat occurences are not used
    else :
        testString = testString.replace(i,"",1)

print "{} and {} are".format(string1, string2),
#If not an anagram, then that statement is added
if isAnagram == False:
    print "NOT ",
print "anagrams."
