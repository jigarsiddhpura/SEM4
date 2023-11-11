def hamming_encode(msg,k):
    encoded_msg = [0] * (len(msg)+k)

    index = 0
    for i in range(len(encoded_msg)):
        if i not in [2**j-1 for j in range(k)]:
            encoded_msg[i] = int(msg[index])
            index += 1

    for i in range(k):
        parity = 0
        pos = 2**i - 1
        for j in range(pos, len(encoded_msg), 2*pos+2):
            parity ^= encoded_msg[j]

        encoded_msg[pos] = parity

    return "".join([str(bit) for bit in encoded_msg])


def hamming_decode(error_msg,k):
    error_pos = 0
    for i in range(k):
        parity = 0
        pos = 2**i - 1
        for j in range(pos, len(encoded_msg), 2*pos+2):
            parity ^= int(encoded_msg[j])

        if parity != int(encoded_msg[pos]):
            error_pos = pos + 1
            break

    if error_pos > 0:
        corrected_msg = list(error_msg)
        corrected_msg[error_pos-1] = str(int(corrected_msg[error_pos-1]) ^ 1)
        corrected_msg = ''.join(corrected_msg)
        print("Error detected and corrected at position", error_pos)
    else:
        corrected_msg = encoded_msg

    message = []
    for i in range(len(corrected_msg)):
        if i not in [2**j-1 for j in range(k)]:
            message.append(corrected_msg[i])

    return ''.join(message)

msg = "1011"

k = 0
while(2**k - 1 < k + len(msg)):
    k += 1

encoded_msg = hamming_encode(msg,k)
print(encoded_msg)

error_pos = 3
error_msg = list(encoded_msg)
error_msg[error_pos] = str(int(encoded_msg[error_pos]) ^ 1)
error_msg = ''.join(error_msg)
print(error_msg)

decoded_msg = hamming_decode(error_msg,k)
print(decoded_msg)
