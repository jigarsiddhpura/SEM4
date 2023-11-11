def checkClass(address):
    ipList = address.split(".")  
    fst = int(ipList[0])
    for key,value in Classes.items():
        if fst in value:
            return key
        
def subnetmastOf(Class):
    for key,value in subnetmast.items():
        if(key==Class) : return value

def ANDof(str1,str2):
    lst = []
    str1List = str1.split(".") 
    str2List = str2.split(".") 
    for a,b in zip(str1List,str2List):
        lst.append(str(int(a) & int(b)))
    return lst
    
ip = (input('Enter ip address: '))

Classes = {'A': [int(i) for i in range(0, 127)], 'B': [int(i) for i in range(128, 191)], 'C': [i for i in range(192, 223)], 'D': [i for i in range(224, 239)], 'E': [i for i in range(240, 255)]}
subnetmast = {'A': '255.0.0.0', 'B':'255.255.0.0', 'C': '255.255.255.0', 'D':'MultiCast', 'E':'Reserved'}
        
addClass = checkClass(ip)
addMask = subnetmastOf(addClass)
print(f'Subnetmask of {ip} is {addMask}')
andList = ANDof(addMask, ip)
ANDstring = ".".join(andList)
print(f'String after AND operation is {ANDstring}')