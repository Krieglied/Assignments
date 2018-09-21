# lab2A-server.py
# Networking Lab 2-2A
# Robert John Graham III
# September 21 2018

from socket import *
s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
s.bind(("",15000))
s.listen(5)
c,a = s.accept()

data = c.recv(1024)
reverse_data = ""
for x in reversed(data):
    reverse_data += x
c.send(reverse_data)
c.close()

