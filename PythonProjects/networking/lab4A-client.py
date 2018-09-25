# lab3A-client.py
# Networking Lab 3-2A
# Robert John Graham III
# September 24 2018

import socket
import struct

# Server info
ip_address = "localhost"
port = 15000
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((ip_address, port))

# String is packed using a default Endianess, and then
# unsigned short, unsigned int, signed short and signed int formats
packed_string = struct.pack('!IIccii', 12345, 56789, '&', '*', 0x7d0, 0b11111010000)
s.send(packed_string)
s.close()
