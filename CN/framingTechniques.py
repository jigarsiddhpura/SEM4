# Byte Stuffing

String = input("Enter str :")
f1 = input("Enter flag1: ")
f2 = input("Enter flag2: ")
esc = input("Enter escape char: ")

stuffedCharList = []

stuffedCharList.append(f1)
for i in String:
    if(i==f1 or i==f2 or i==esc):
        stuffedCharList.append(esc)
    stuffedCharList.append(i)
stuffedCharList.append(f2) 

stuffedStr = "".join(stuffedCharList)
print("String after Byte Stuffing:", stuffedStr)

# Bit Stuffing

# msg = input("Enter Message :")
# stuffedBitList = []
# ctr = 0

# for i in msg:
#     stuffedBitList.append(i)
#     if i=='1': 
#         ctr+=1
#     if i=='0': 
#         ctr = 0
#     if ctr==5: 
#         stuffedBitList.append('0')
#         ctr = 0

# stuffedBitStr = "".join(stuffedBitList)
# print("Stuffed Bit String: ",stuffedBitStr)

# Character Count

# fc = int(input("Enter frame count: "))
# frameList = [input("Enter frame: ") for i in range(fc)]
# stuffedStr = ""

# for i in frameList:
#     stuffedStr += str(len(i)+1) + i

# print("Stuffed Message: ", stuffedStr)








    
