from scapy.all import *
from scapy_http import http
from netfilterqueue import NetfilterQueue

def modify(packet):
    pkt = IP(packet.get_payload())
    # packet.set_payload(pkt)
    if IP in pkt:
        ip_src=pkt[IP].src
        ip_dst=pkt[IP].dst
        print(ip_dst.net)
    if TCP in pkt:
        tcp_sport=pkt[TCP].sport
        tcp_dport=pkt[TCP].dport
    print(ip_src, tcp_sport, ip_dst, tcp_dport)
    # packet.accept()
    packet.drop()
    send(pkt)

nfqueue = NetfilterQueue()
nfqueue.bind(1, modify)
try:
    print("waiting for data")
    nfqueue.run()
except KeyboardInterrupt:
    pass
