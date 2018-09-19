# lab1D-client.py
# Networking Lab 1-2D
# Robert John Graham III
# September 19 2018

from socket import *
s = socket(AF_INET6, SOCK_DGRAM)
s.connect(("localhost",15000))
s.send("Hello World")
s.send("Second Hello")
s.send("Third Hello")
s.close()

