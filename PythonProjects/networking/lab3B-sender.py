# lab3B-sender.py
# Networking Lab 3-2B
# Robert John Graham III
# September 24 2018

import socket
import json

# Server info
ip_address = "localhost"
port = 15000
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect((ip_address, port))
# User input
test_string = raw_input("Please input any number of words to test::: ")
s.send(test_string)
# The connection port on the client is + 1 from the port set up intitally
s2.bind((ip_address, s.getsockname()[1] + 1))
c,a = s2.recvfrom(1024)
output = json.loads(c)
# The information is printed once received
print("The list of words from largest to smallest is: {}").format(output)
s.close()
s2.close()
