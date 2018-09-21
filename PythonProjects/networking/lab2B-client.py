# lab2B-client.py
# Networking Lab 2-2B
# Robert John Graham III
# September 21 2018

from socket import *
import json
s = socket(AF_INET, SOCK_DGRAM)
s.connect(("localhost",15000))
test_data = {1:"First",2:"Second",3:"Third",4:"Fourth"}
s.send(json.dumps(test_data))
