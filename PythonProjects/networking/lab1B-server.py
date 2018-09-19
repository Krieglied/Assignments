# lab1A-server.py
# Networking Lab 1-2A
# Robert John Graham III
# September 19 2018

from socket import *
s = socket(AF_INET6, SOCK_STREAM)
s.bind(("",15000))
s.listen(5)
c,a = s.accept()

print(c)
print(a)
data = c.recv(1024)
print(data)
c.send("Hello Yourself")
c.send("Goodbye")
c.close()

