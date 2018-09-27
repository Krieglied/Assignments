# tcp-server.py
# Networking Lab 4-2A
# Robert John Graham III
# September 26 2018

import socket
import struct
import select
import sys
import Queue

# Server info
ip_address = "localhost"
port = 15000
threads = []
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setblocking(0)
s.bind((ip_address, port))
# How many sockets to listen for to connect
max_connections = 5
s.listen(max_connections)
inputs = [s]
outputs = []
message_queues = []
while inputs:
    readable, writeable, exceptional = select.select(inputs, outputs, inputs)

    for conn in readable:
        if conn is s:
            connection, address = s.accept()
            connection.setblocking(0)
            inputs.append(connection)
        else:
            data = connection.recv(1024)
            message_queues.append(data)
            print(data)
            for conn in inputs:
                if conn is s:
                    continue
                else:
                    for message in message_queues:
                        conn.send(message)
s.close()
