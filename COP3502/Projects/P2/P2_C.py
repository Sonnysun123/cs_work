import console_gfx
def to_hex_string(data):
    output = ""
    for i in range(0, len(data)):
       # if i%2 == 0:
        #    output += str(trash[i])
        #else:
            if data[i] < 10:
                convert = str(data[i])
            elif data[i] == 10:
                convert = 'a'
            elif data[i] == 11:
                convert = 'b'
            elif data[i] == 12:
                convert = 'c'
            elif data[i] == 13:
                convert = 'd'
            elif data[i] == 14:
                convert = 'e'
            elif data[i] == 15:
                convert = 'f'
            output += convert
    return output
def count_runs(input_data):
    count = 0
    runs = 1
    for i in range(len(input_data)-1):
        if input_data[i] == input_data[i+1]:
            count += 1
            if count == 15:
                runs += 1
                count = 0
        else:
            count = 0
            runs += 1
    return runs

def encode_rle(flat_data):
    count = 1
    res = []
    for i in range(len(flat_data)-1):
        if flat_data[i] == flat_data[i+1] and count < 15:
            count += 1
        else:
            res.append(count)
            res.append(flat_data[i])
            count = 1
    res.append(count)
    res.append(flat_data[-1])
    return res
def get_decoded_length(input_data):
    count = 0
    for i in range(len(input_data)):
        if i%2 == 0:
            count += input_data[i]
    return count
def decode_rle(input_data):
    res = []
    for i in range(1, len(input_data), 2):
        res.extend(input_data[i-1] * input_data[i:i+1])
    return res
def string_to_data(data_string):
    res = []
    for i in range(len(data_string)):

            result = 0
            if data_string[i].isdigit():
                result = data_string[i]
            elif data_string[i] == 'a':
                result = 10
            elif data_string[i] == 'b':
                result = 11
            elif data_string[i] == 'c':
                result = 12
            elif data_string[i] == 'd':
                result = 13
            elif data_string[i] == 'e':
                result = 14
            elif data_string[i] == 'f':
                result = 15
            res.append(int(result))
    return res
def to_rle_string(input_data):
    res = ''
    for i in range(len(input_data)):
        if i % 2 == 0:
            res += str(input_data[i])
        else:
            if input_data[i] <= 9:
                res += str(input_data[i])
            elif input_data[i] == 10:
                res += "a"
            elif input_data[i] == 11:
                res += "b"
            elif input_data[i] == 12:
                res += "c"
            elif input_data[i] == 13:
                res += "d"
            elif input_data[i] == 14:
                res += "e"
            elif input_data[i] == 15:
                res += "f"
            res += ":"
    return res[:-1]
def string_to_rle(input_data):
    a = input_data.split(':')
    rle_byte_data = []
    for i in range(len(a)):
        rle_byte_data.append(int(a[i][0:-1]))
        if a[i][-1] == 'f':
            rle_byte_data.append(15)
        elif a[i][-1] == 'a':
            rle_byte_data.append(10)
        elif a[i][-1] == 'b':
            rle_byte_data.append(11)
        elif a[i][-1] == 'c':
            rle_byte_data.append(12)
        elif a[i][-1] == 'd':
            rle_byte_data.append(13)
        elif a[i][-1] == 'e':
            rle_byte_data.append(14)
        else:
            rle_byte_data.append(int(a[i][-1]))
    return rle_byte_data


def display_menu():
    print("\nRLE Menu\n"
          "--------")
    print("0. Exit\n"
          "1. Load File\n"
          "2. Load Test Image\n"
          "3. Read RLE String\n"
          "4. Read RLE Hex String\n"
          "5. Read Data Hex String\n"
          "6. Display Image\n"
          "7. Display RLE String\n"
          "8. Display Hex RLE Data\n"
          "9. Display Hex Flat Data\n")
def main():
    print("Welcome to the RLE image encoder!\n")
    print("Displaying Spectrum Image:")
    console_gfx.display_image(console_gfx.test_rainbow)
    print()
    while True:
        display_menu()
        option = int(input("Select a Menu Option: "))
        if option == 0:
            break
        elif option == 1:
            file_name =  input("Enter name of file to load: ")
            image_data = console_gfx.load_file(file_name)
        elif option == 2:
            image_data = console_gfx.test_image
            print("Test image trash loaded.")
        elif option == 3:
            input_data = input("Enter an RLE string to be decoded: ")
            image_data = decode_rle(string_to_rle(input_data))
        elif option == 4:
            data_string = input("Enter the hex string holding RLE trash: ")
            image_data = decode_rle(string_to_data(data_string))
        elif option == 5:
            string = input("Enter the hex string holding flat trash: ")
            image_data = encode_rle(string_to_data(string))
        elif option == 6:
            print("Displaying image...")
            console_gfx.display_image(image_data)
        elif option == 7:
            print("RLE representation:", to_rle_string(image_data))
            print(f"RLE representation: {image_data}")
        elif option == 8:
            print("RLE hex values:", to_hex_string(image_data))
        elif option == 9:
            print("Flat hex values:", to_hex_string(decode_rle(image_data)))


if __name__ == '__main__':
    main()