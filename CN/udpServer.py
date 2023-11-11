import socket 

udp_host = socket.gethostname()
udp_port = 12345

#print type(sock) ==> 'type' can be used to see type  of any variable ('sock' here)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sock.bind((udp_host, udp_port))                               # for binding & listening ONLY FOR SERVER

while True:
    print("Waiting for client...")
    data , addr = sock.recvfrom(1024)
    if( not data or data.decode('utf-8')=='close'):
        break
    print(f"data received : {data} from {addr}")

print("Connection closed")