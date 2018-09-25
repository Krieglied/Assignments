# lab4A-server.py
# Networking Lab 4-2A
# Robert John Graham III
# September 25 2018

import socket
import struct

# Server info
ip_address = "localhost"
port = 15000
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((ip_address, port))
# How many sockets to listen for to connecct
s.listen(5)
# Specific connect information for the socket
c,a = s.accept()

# Data received from the client
data = c.recv(1024)
int1, int2, char1, char2, hex1, bin2 = struct.unpack('!IIccii', data)
print("Client Output: {} {} {} {} {} {}").format(int1, int2, char1, 
        char2, hex(hex1), bin(bin2))
c.close()
s.close()
