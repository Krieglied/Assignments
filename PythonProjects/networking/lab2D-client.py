# lab2D-client.py
# Networking Lab 2-2D
# Robert John Graham III
# September 21 2018

from socket import *
domain_name = raw_input("Please input a domain name::: ")
ip_address = gethostbyname(domain_name)
print(ip_address)
name = gethostbyaddr(ip_address)
print(name[0])
