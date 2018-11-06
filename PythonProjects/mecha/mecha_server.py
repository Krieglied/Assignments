# mecha_server.py

import socket
from validation.validation import int_validation
import movement.field

HOST = 'localhost'
PORT = 3052
field = movement.field.Field(20, 20)
list_of_players = {}

max_players = 5
print("Please select the maximum number of players (up to {})").format(
    max_players)
num_of_players = int_validation(max_players)
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(num_of_players)
ready_up = False
while ready_up is False:
    connection, address = server.accept()
    data = connection.recv(1024)