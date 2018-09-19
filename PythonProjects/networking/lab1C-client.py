# lab1C-client.py
# Networking Lab 1-2C
# Robert John Graham III
# September 19 2018

from socket import *
s = socket(AF_INET, SOCK_DGRAM)
s.connect(("localhost",15000))

s.send("Hello World")
s.send("Second Hello")
s.send("Third Hello")
s.close()
