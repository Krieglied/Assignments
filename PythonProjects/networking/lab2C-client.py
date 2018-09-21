# lab2C-client.py
# Networking Lab 2-2C
# Robert John Graham III
# September 21 2018

from socket import *
s = socket(AF_INET, SOCK_DGRAM)
s.connect(("localhost",15000))
host_ip = gethostbyname(gethostname())
s.send(host_ip)
host_name = gethostname()
s.send(host_name)
