def hamming_encode(message):
    """
    Encodes the given message using Hamming code and returns the encoded message.
    """
    # Determine the number of parity bits needed (k)
    k = 1
    while 2 ** k - 1 < len(message) + k :
        k += 1


    # Create an empty encoded message.
    encoded_message = [0] * (len(message) + k)

    # Copy the message bits into the encoded message, leaving spaces for the parity bits.
    j = 0
    for i in range(len(encoded_message)):
        if i+1 not in [2**n for n in range(k)]:
            encoded_message[i] = int(message[j])
            j += 1

    # Calculate the parity bits and insert them into the encoded message.
    for i in range(k):
        # Calculate the bit position for this parity bit.
        pos = 2**i - 1

        # Calculate the parity value for this bit position.
        parity = 0
        for j in range(pos, len(encoded_message), 2*pos+2):       # ⭐⭐⭐
            parity ^= int(encoded_message[j])

        # Insert the parity bit into the encoded message.
        encoded_message[pos] = parity

        print("parity = ",parity)

    # Return the encoded message as a string.
    return ''.join([str(bit) for bit in encoded_message])


def hamming_decode(encoded_message):
    """
    Decodes the given encoded message using Hamming code and returns the original message.
    If an error is detected, corrects the error and returns the corrected message.
    """
    # Determine the number of parity bits in the encoded message.
    k = 1
    while 2 ** k < len(encoded_message) + 1:
        k += 1

    # Check the parity bits to see if an error occurred and correct if necessary.
    error_pos = 0
    for i in range(k):
        # Calculate the bit position for this parity bit.
        pos = 2**i - 1

        # Calculate the parity value for this bit position.
        parity = 0
        for j in range(pos, len(encoded_message), 2*pos+2):
            parity ^= int(encoded_message[j])

        # If the parity value doesn't match the parity bit in the encoded message,
        # there's an error in the transmission.
        if parity != int(encoded_message[pos]):
            error_pos += pos + 1

    # If an error was detected, correct it by flipping the bit at the error position.
    if error_pos > 0:
        corrected_message = list(encoded_message)
        corrected_message[error_pos-1] = str(int(corrected_message[error_pos-1]) ^ 1)
        corrected_message = ''.join(corrected_message)

        # Print a message to indicate that an error was corrected.
        print("Error detected and corrected at position", error_pos)
    else:
        corrected_message = encoded_message

    # Extract the original message bits from the corrected encoded message.
    message = []
    for i in range(len(corrected_message)):
        if i+1 not in [2**n for n in range(k)]:
            message.append(corrected_message[i])

    # Return the original message as a string.
    return ''.join(message)


# Example usage:
message = "1011"
encoded_message = hamming_encode(message)
print("Encoded message:", encoded_message)

# Simulate an error by flipping one of the bits in the encoded message.
error_pos = 3
corrupted_message = list(encoded_message)
corrupted_message[error_pos] = str(int(corrupted_message[error_pos]) ^ 1)
corrupted_message = ''.join(corrupted_message)
print("Corrupted message: ", corrupted_message)

decoded_message = hamming_decode(corrupted_message)
print("Decoded message: ", decoded_message)