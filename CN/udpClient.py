import socket 

udp_host = socket.gethostname()
udp_port = 12345

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # For UDP ⭐⭐⭐

print(f"Udp target ip : {udp_host}")
print(f"Udp target port : {udp_port}")

while True:
    msg = input("Enter the msg : ")
    if(msg=='close'):
        break
    sock.sendto(msg.encode('utf-8'),(udp_host,udp_port))

print("Connection closed")