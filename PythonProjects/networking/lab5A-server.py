# lab5A-server.py
# Networking Lab 5-2A
# Robert John Graham III
# September 27 2018

import socket
import struct
import random
import time

HOST = 'localhost'
PORT = 15000
rando = random.randint(0, 100)
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))

server.listen(5)
connection, address = server.accept()
while True:
    data = connection.recv(1024)
    received = struct.unpack('=i', data)
    print(received[0])
    if received[0] is rando:
        connection.send("You have guessed correctly. MUCH SUCCESS!!")
        break
    else:
        if received[0] < rando:
            message = "Your guess is lower than the generated number. MUCH FAIL!!"
            connection.send(message)
        else:
            message = "Your guess is greater than the generated number. MUCH FAIL!!"
            connection.send(message)
time.sleep(5)
server.close()
