# lab2C-server.py
# Networking Lab 2-2C
# Robert John Graham III
# September 21 2018

from socket import *
s = socket(AF_INET, SOCK_DGRAM)
s.bind(("",15000))

data, addr = s.recvfrom(1024)
print("IP Address: {}").format(data)
data, addr = s.recvfrom(1024)
print("Host Name: {}").format(data)
s.close()

