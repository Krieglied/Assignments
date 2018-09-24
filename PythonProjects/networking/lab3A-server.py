# lab3A-server.py
# Networking Lab 3-2A
# Robert John Graham III
# September 24 2018

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
# Data is unpacked using Little Endian
unpacked_string = struct.unpack('<HIhi', data)
print("Little Endian: {}").format(unpacked_string)
# Data is unpacked using Big Endian
unpacked_string = struct.unpack('>HIhi', data)
print("Big Endian: {}").format(unpacked_string)
c.close()
s.close()
