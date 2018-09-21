# lab2B-server.py
# Networking Lab 2-2B
# Robert John Graham III
# September 21 2018

from socket import *
import json
s = socket(AF_INET, SOCK_DGRAM)
s.bind(("",15000))

data, addr = s.recvfrom(1024)
received = json.loads(data)
print(type(data))
print(data)
print(type(received))
print(received)
print(received["1"])
s.close()

