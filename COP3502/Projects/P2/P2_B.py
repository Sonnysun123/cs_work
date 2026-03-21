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
def count_runs(flat_data):
    count = 0
    runs = 1
    for i in range(len(flat_data)-1):
        if flat_data[i] == flat_data[i+1]:
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
def get_decoded_length(rle_data):
    count = 0
    for i in range(len(rle_data)-1):
        if i%2 == 0:
            count += rle_data[i]
    return count
def decode_rle(rle_data):
    res = []
    for i in range(1, len(rle_data), 2):
        res.extend(rle_data[i-1] * [rle_data[i]])
    return res
def string_to_data(data_string):
    res = []
    for i in range(len(data_string)):
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
