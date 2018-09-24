# lab3B-receiver.py
# Networking Lab 3-2B
# Robert John Graham III
# September 24 2018

import socket
import json
# Function to correctly handle sorting the words according to word length
def sort_words(input):
    return len(input)

# Server info
ip_address = "localhost"
port = 15000
# The port to connect to on the client
port2 = port + 1
words = []
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((ip_address, port))
c,a = s.recvfrom(1024)
# The data received from the client is broken into words
words = c.split(" ")
# The words are then sorted by length of word, from largest to smallest
words.sort(reverse=True, key=sort_words)
s2.connect((a[0], a[1] + 1))
# The information is then send back to the client on the second port
send_data = json.dumps(words)
s2.send(send_data)
s.close()
s2.close()
