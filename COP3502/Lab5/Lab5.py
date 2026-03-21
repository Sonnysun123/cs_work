def hex_char_decode(digit):
    if digit.upper() == "A":
        return 10
    if digit.upper() == "B":
        return 11
    if digit.upper() == "C":
        return 12
    if digit.upper() == "D":
        return 13
    if digit.upper() == "E":
        return 14
    if digit.upper() == "F":
        return 15
    else:
        return int(digit)

def hex_string_decode(hex):
    if hex[1] == "x" or hex[1] == "X":
        hex = hex[2:]
    sum = 0
    power = len(hex)-1
    for i in hex:
        num = hex_char_decode(i)
        sum += num * (16**power)
        power -= 1
    return sum

def binary_string_decode(binary):
    if binary[1] == "b" or binary[1] == "B":
        binary = binary[2:]
    sum = 0
    power = len(binary)-1
    for i in binary:
        sum += int(i) * (2**power)
        power -= 1
    return sum

def binary_to_hex(binary):
    if binary[1] == "b" or binary[1] == "B":
        binary = binary[2:]
    hex = ""
    l = len(binary)
    if l % 4 == 1:
        binary = "000" + binary
    if l % 4 == 2:
        binary = "00" + binary
    if l % 4 == 3:
        binary = "0" + binary
    l = len(binary)
    for i in range(0, l, 4):
        bin = binary[l-4-i:l-i]
        val = binary_string_decode(bin)
        if val >= 10:
            hex = chr(65 + (val - 10)) + hex
        else:
            hex = str(val) + hex
    return hex

def main():
    while True:
        print("Decoding Menu\n"
              "-------------\n"
              "1. Decode hexadecimal\n"
              "2. Decode binary\n"
              "3. Convert binary to hexadecimal\n"
              "4. Quit\n")
        selection = int(input("Please enter an option: "))
        if selection == 4:
            print("Goodbye!")
            break
        else:
            value = input("Please enter the numeric string to convert: ")
            if selection == 1:
                answer = hex_string_decode(value)
            if selection == 2:
                answer = binary_string_decode(value)
            if selection == 3:
                answer = binary_to_hex(value)
            print(f"Result: {answer}\n")

main()