
def print_backwards(word):
    if len(word) == 0:
        return
    end = word[-1]
    word = word[:-1]
    print(end, end = "")
    print_backwards(word)


def format_names(names):
    if not names:
        return []
    name = names[0]
    if ',' in name:
        comma_index = name.index(',')
        last_name = name[comma_index+2:]
        first_name = name[:comma_index]
    else:
        last_name, first_name = name.split(' ')
    return [f"{first_name}, {last_name}"] + format_names(names[1:])


def sum_a(example_data):
    sum = 0
    for dictionary in example_data:
        for key in dictionary:
            if key == "a":
                sum += dictionary[key]
    return sum


def process_list(list_data):
    res = []
    for i in range(len(list_data)):
        if i % 2 == 0:
            res.append(str(list_data[i]))
    for i in range(len(list_data)):
        if i % 2 == 1:
            res.append(10*list_data[i])
    return res

