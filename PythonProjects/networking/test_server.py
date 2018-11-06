import socket, struct

address = '0.0.0.0'
port = 1337
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((address, port))

