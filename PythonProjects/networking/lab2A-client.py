# lab2A-client.py
# Networking Lab 2-2A
# Robert John Graham III
# September 21 2018

from socket import *
s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
s.connect(("localhost",15000))

s.send("Hello World")
data = s.recv(1024)
print(data)
