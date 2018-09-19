# lab1A-client.py
# Networking Lab 1-2A
# Robert John Graham III
# September 19 2018

from socket import *
s = socket(AF_INET, SOCK_STREAM)
s.connect(("localhost",15000))

s.send("Hello World")
resp = s.recv(1024)
print(resp)
resp = s.recv(1024)
print(resp)
resp = s.recv(1024)
print(resp)
