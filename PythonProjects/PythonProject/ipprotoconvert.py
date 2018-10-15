"""
Filename: ipprotoconvert.py
Description: This file contains a list of all the protocol
            nubmers and keywords and a function to convert the number
            to the keyword

"""


def protoName(protoNum):
    protoDict={
        0:"HOPOPT", 1:"ICMP", 2:"IGMP", 3:"GGP", 4:"IP-in-IP", 5:"ST",
        6:"TCP", 7:"CBT", 8:"EGP", 9:"IGP", 10:"BBN-RCC-MON",
        11:"NVP-II", 12:"PUP", 13:"ARGUS", 14:"EMCON", 15:"XNET",
        16:"CHAOS",17:"UDP", 18:"MUX", 19:"DCN-MEAS", 20:"HMP",
        21:"PRM",22:"XNS-IDP",23:"TRUNK-1",24:"TRUNK-2",25:"LEAF-1",
        26:"LEAF-2",27:"RDP",28:"IRTP",29:"ISO-TP4",30:"NETBLT",
        31:"MFE-NSP",32:"MERIT-INP",33:"DCCP",34:"3PC",35:"IDPR",
        36:"XTP",37:"DDP",38:"IDPR-CMTP",39:"TP++",40:"IL",
        41:"IPv6",42:"SDRP",43:"IPv6-Route",44:"IPv6-Frag",45:"IDRP",
        46:"RSVP", 47:"GREs", 48:"DSR", 49:"BNA", 50:"ESP",
        51:"AH",52:"I-NLSP",53:"SWIPE",54:"NARP",55:"MOBILE",
        56:"TLSP",57:"SKIP",58:"IPv6-ICMP",59:"IPv6-NoNxt",60:"IPv6-Opts",
        61:"Any-Host",62:"CFTP",63:"Any-Local",64:"SAT-EXPAK",65:"KRYPTOLAN",
        66:"RVD",67:"IPPC",68:"Any-FS",69:"SAT-MON",70:"VISA",
        71:"IPCU",72:"CPNX",73:"CPHB",74:"WSN",75:"PVP",
        76:"BR-SAT-MON",77:"SUN-ND",78:"WB-MON",79:"WB-EXPAK",80:"ISO-IP",
        81:"VMTP",82:"SECURE-VMTP",83:"VINES",84:"TTP",85:"NSFNET-IGP",
        86:"DGP",87:"TCF",88:"EIGRP",89:"OSPF",90:"SPRITE-RPC",
        91:"LARP",92:"MTP",93:"AX.25",94:"OS",95:"MICP",
        96:"SCC-SP",97:"ETHERIP",98:"ENCAP",99:"Any-PrivEncypt",100:"GMTP",
        101:"IFMP",102:"PNNI",103:"PIM",104:"ARIS",105:"SCPS",
        106:"QNX",107:"A/N",108:"IPComp",109:"SNP",110:"Compaq-Peer",
        111:"IPC-in-IP",112:"VRRP",113:"PGM",114:"Any 0-Hop",115:"L2TP",
        116:"DDX",117:"IATP",118:"STP",119:"SRP",120:"UTI",
        121:"SMP",122:"SM",123:"PTP",124:"IS-IS over IPv4",125:"FIRE",
        126:"CRTP",127:"CRUDP",128:"SSCOPMCE",129:"IPLT",130:"SPS",
        131:"PIPE",132:"SCTP",133:"FC",134:"RSVP-E2E-IGNORE",135:"Mobility Header",
        136:"UDPLite",137:"MPLS-in-IP",138:"Manet",139:"HP",140:"Shim6",
        141:"WESP", 142:"ROHC"
    }
    if protoNum in protoDict.keys():
        return protoDict[protoNum]
    else:
        return "Unassigned"
def tcpFlags(flags):
    flag_str = ""
    if flags >= 256:
        flag_str += "[NS]"
        flags -= 256
    if flags >= 128:
        flag_str += "[CWR]"
        flags -= 128
    if flags >= 64:
        flag_str += "[ECE]"
        flags -= 64
    if flags >= 32:
        flag_str += "[URG]"
        flags -= 32
    if flags >= 16:
        flag_str += "[ACK]"
        flags -= 16
    if flags >= 8:
        flag_str += "[PSH]"
        flags -= 8
    if flags >= 4:
        flag_str += "[SYN]"
        flags -= 4
    if flags >= 2:
        flag_str += "[RST]"
        flags -= 2
    if flags >= 1:
        flag_str += "[FIN]"
    return flag_str
