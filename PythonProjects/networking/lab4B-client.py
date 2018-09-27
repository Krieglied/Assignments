# lab1C-client.py
# Networking Lab 1-2C
# Robert John Graham III
# September 19 2018

import socket
import struct

s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_UDP)

source_ip = '192.168.31.128'
dest_ip = '192.168.31.128'
# dest_ip = socket.gethostbyname('www.google.com')

# ip header fields
ip_ihl = 5
ip_ver = 4
ip_tos = 0
ip_tot_len = 0  # kernel will fill the correct total length
ip_id = 54321   #Id of this packet
ip_frag_off = 0
ip_ttl = 255
ip_proto = socket.IPPROTO_UDP
ip_check = 0    # kernel will fill the correct checksum
ip_saddr = socket.inet_aton ( source_ip )   #Spoof the source ip address if you want to
ip_daddr = socket.inet_aton ( dest_ip )

ip_ihl_ver = (ip_ver << 4) + ip_ihl

# the ! in the pack format string means network order
ip_header = struct.pack('!BBHHHBBH4s4s' , ip_ihl_ver, ip_tos, ip_tot_len, ip_id, ip_frag_off, ip_ttl, ip_proto, ip_check, ip_saddr, ip_daddr)

data = 'Hello World!'
sport = 4711    # arbitrary source port
dport = 15000   # arbitrary destination port
length = 8 + len(data);
checksum = 0
udp_header = struct.pack('!HHHH', sport, dport, length, checksum)

s.sendto(ip_header+udp_header+data, ('',0))
data = 'Test 2'

s.sendto(ip_header+udp_header+data, ('',0))
data = 'Final Test'
s.sendto(ip_header+udp_header+data, ('',0))

s.close()

