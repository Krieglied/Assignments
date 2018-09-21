# lab2C-client.py
# Networking Lab 2-2C
# Robert John Graham III
# September 21 2018

from socket import *
s = socket(AF_INET, SOCK_DGRAM)
s.connect(("192.168.31.128",15000))
host_ip = s.getsockname()[0]
s.send(host_ip)
host_name = gethostname()
s.send(host_name)
