# lab5A-client.py
# Networking Lab 5-2A
# Robert John Graham III
# September 27 2018

import socket
import struct

def int_validation():
    user_input = raw_input("Please input an int to guess::: ")
    try:
        user_input = int(user_input)
    except ValueError:
        print("Not a valid int.")
        user_input = int_validation()
    return user_input

HOST = 'localhost'
PORT = 15000
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.connect((HOST, PORT))

while True:
    guess = int_validation()
    packed_data = struct.pack("=i", guess)
    server.send(packed_data)
    data = server.recv(1024)
    print(data)
    if data ==  "You have guessed correctly. MUCH SUCCESS!!":
        break
server.close()
