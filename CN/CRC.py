def CRC(msg, divisor):

    msg += '0' * (len(divisor)-1)

    msg = [int(i) for i in msg]
    divisor = [int(i) for i in divisor]

    for i in range(len(msg) - len(divisor) + 1):
        if msg[i] == 1:
            for j in range(len(divisor)):
                msg[i+j] ^= divisor[j]

    return ''.join([str(bit) for bit in msg[-(len(divisor) - 1): ]])

def checkCRC(data, divisor):
    return 0 if(int(CRC(data,divisor)) != 0 ) else 1

choice = int(input("Enter 1 for transmission, 2 for reception , 3 to exit : "))

while(choice < 3):
    if(choice == 1):
        message = input("Enter message : ")
        divisor = input("Enter divisor : ")
        # message = "1101011011"
        # divisor = "10011"
        crc = CRC(message, divisor)
        print(crc)
    if(choice==2):
        transmittedData = input("Enter transmitted data : ")
        divisor = input("Enter divisor : ")
        # transmittedData = "1100101011010"
        # divisor = "10101"
        error = checkCRC(transmittedData,divisor)
        print("Transmitted without error ") if(error == 1) else print("Transmitted with error ")
    choice = int(input("Enter 1 for transmission, 2 for reception , 3 to exit : "))
    
