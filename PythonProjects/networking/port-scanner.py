# port-scanner.py

# Bonus Lab
# Robert John Graham III
# September 24 2018

import socket
import struct
import sys
from uuid import getnode as get_mac

position = 1
ip_address = ""
port_start, port_end, ip = [],0,0
proto = ""
for args in sys.argv:
    if position == 1:
        ip_address = sys.argv[position]
    if position == 2:
        port_start = sys.argv[position].split("-")[0]
        port_end = sys.argv[position].split("-")[1]
    if position == 3:
        ip_type = sys.argv[position]
    if position == 4:
        proto = sys.argv[position]
    position += 1
src_mac = hex(get_mac())
dest_mac = "FF:FF:FF:FF:FF:FF"
ether_type = 0x0804

src_ip = [l for l in ([ip for ip in socket.gethostbyname_ex(socket.gethostname())[2] 
    if not ip.startswith("127.")][:1], [[(s.connect(('8.8.8.8', 53)), 
        s.getsockname()[0], s.close()) for s in [socket.socket(socket.AF_INET, 
            socket.SOCK_DGRAM)]][0][1]]) if l][0][0]
dest_ip = ip_address
ip_ver = int(ip_type)
ip_vhl = 5
ip_ver = (ip_ver << 4 ) + ip_vhl

ip_dsc = 0
ip_ecn = 0

ip_dfc = (ip_dsc << 2 ) + ip_ecn

ip_tol = 0

ip_idf = 54321

ip_rsv = 0
ip_dtf = 0
ip_mrf = 0
ip_frag_offset = 0

ip_flg = (ip_rsv << 7) + (ip_dtf << 6) + (ip_mrf << 5) + (ip_frag_offset)

ip_ttl = 255

ip_proto = socket.IPPROTO_TCP

ip_chk = 0

ip_saddr = socket.inet_aton(src_ip)
ip_daddr = socket.inet_aton(dest_ip)

