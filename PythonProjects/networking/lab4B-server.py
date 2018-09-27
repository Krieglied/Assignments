# lab1C-server.py
# Networking Lab 1-2C
# Robert John Graham III
# September 19 2018

from socket import *
import struct
ip_address = 'localhost'
port = 15000
s = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)
s.bind((ip_address, port))
c,a = s.recvfrom(1024)
data = c
print(data[46::])
c,a = s.recvfrom(1024)
data = c
print(data[46::])
c,a = s.recvfrom(1024)
data = c
print(data[46::])
s.close()
