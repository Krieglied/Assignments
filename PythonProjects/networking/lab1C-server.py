# lab1C-server.py
# Networking Lab 1-2C
# Robert John Graham III
# September 19 2018

from socket import *
s = socket(AF_INET, SOCK_DGRAM)
s.bind(("",15000))
c,a = s.recvfrom(1024)
print(c)
print(a)
c,a = s.recvfrom(1024)
print(c)
print(a)
c,a = s.recvfrom(1024)
print(c)
print(a)
s.close()
