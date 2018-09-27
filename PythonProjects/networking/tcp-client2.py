# tcp-client.py
# Networking Lab 4-2A
# Robert John Graham III
# September 26 2018

import socket
import struct
import time

# Server info
ip_address = "localhost"
port = 15000
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((ip_address, port))
s.send("2")
while True:
    data = s.recv(1024)
    print(data)
s.close()
