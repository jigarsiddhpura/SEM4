import socket

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    connectionObj , address = s.accept()
    with connectionObj:
        print(f"Connected to client @ address {address}")
        while True:
            data = connectionObj.recv(1024)
            if (not data or data.decode('utf-8')=='close'):      # decoding from binary to str format ⭐⭐⭐
                break
            print(f"Received data = {data}")
            info = input("Enter data for client : ")
            bytes_data = info.encode('utf-8')                    # encoding to binary format ⭐⭐⭐
            connectionObj.sendall(bytes_data)

print("Connection closed")

