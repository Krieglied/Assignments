# test_main.py

from search_data import *
from listener import *
from report import *
from ipprotoconvert import *

#output = search_file("2018_10_4_packet.log")
#print(output)
#listening()

# Test Section to see if filter search works on a provide data set

#test_list = []
#test_element = {"No.": 1, "Time": "test","Source Address":"192.168.31.128","Destination Address":"192.168.31.31","Protocol":6,"Total Length":17}
#test_list.append(test_element)
#test_element = {"No.": 2, "Time": "test","Source Address":"192.168.31.129","Destination Address":"192.168.30.29","Protocol":6,"Total Length":23}
#test_list.append(test_element)
#test_element = {"No.": 3, "Time": "test","Source Address":"192.168.31.130","Destination Address":"192.168.31.31","Protocol":7,"Total Length":17}
#test_list.append(test_element)
#test_element = {"No.": 4, "Time": "test","Source Address":"192.168.31.131","Destination Address":"192.168.30.31","Protocol":6,"Total Length":17}
#test_list.append(test_element)
#test_element = {"No.": 5, "Time": "test","Source Address":"192.168.31.132","Destination Address":"192.168.30.28","Protocol":9,"Total Length":17}
#test_list.append(test_element)
#output = []
#output = display_table(0, test_list)
#output = search_list(test_list)
#print(output)
test_str = tcpFlags(16)
print(test_str)
test_str = tcpFlags(4)
print(test_str)
test_str = tcpFlags(116)
print(test_str)
test_str = tcpFlags(42)
print(test_str)
test_str = tcpFlags(203)
print(test_str)
test_str = tcpFlags(254)
print(test_str)
test_str = tcpFlags(65)
print(test_str)
