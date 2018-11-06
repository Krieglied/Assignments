import socket, struct

address = '0.0.0.0'
port = 1337
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((address, port))
server.listen(5)
c,a = server.accept()
data = c.recv(1024)
output = struct.unpack("!LL", data)
print output
if a[1] == 12345:
    print('success')
    if output[0] == 0x802:
        print('query mode')
        packed_string = struct.pack("!LL", 0x800, 0x0000)
        c.send(packed_string)
c,a = server.accept()
data = c.recv(1024)
output = struct.unpack("!LL", data)
print(output)
print(c)
print(a)
if a[1] == 54321:
    if output[0] == 0x803:
        print("MASS SUCCESS")
        data = int("THIS IS A TEST")
        packed_string = struct.pack("!LL", data, 0x0000)
server.close()
