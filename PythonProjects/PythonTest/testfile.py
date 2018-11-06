#!/usr/bin/env python

import os, glob, subprocess

"""
# Given a list of strings (['string1', 'string2', 'string3']), reverse all of the characters, and
# join them all together into a single string, with each previous word separated by spaces
# (the above example becomes '1gnirts 2gnirts 3gnirts')
"""
def first_test(string_list):
    output = ""
    pos = 0
    for string in string_list:
        output += string[::-1]
        if pos < len(string_list):
            output += " "
        pos += 1
    return output

"""
# Given a directory path, find each file that ends with '.txt', and create a dictionary,
# where each element consists of the filename, and its contents (e.g., if we had a file called
# "foo.txt" that contained "AAAA", our dictionary would look like: 
# { "evalFolder\\foo.txt" : "AAAA" }). This dictionary will be our return item.
"""
def third_test(fname):
    output = {}
    os.chdir(fname)
    for file in glob.glob("*.txt"):
        file_read = open(file, "r")
        output[file] = file_read.read()
        file_read.close()
    return output
