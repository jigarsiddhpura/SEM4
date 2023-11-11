import socket

HOST = '127.0.0.1'       # The server's hostname or IP address
PORT = 65432             # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    while True:
        info = input("Enter data to send server ")
        bytes_data = info.encode('utf-8')
        s.sendall(bytes_data)
        data = s.recv(1024)
        if (not data or data.decode('utf-8')=='close'):
            break
        print(f"Received from server : {data}")

print("Connection closed")

