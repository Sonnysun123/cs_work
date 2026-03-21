char = int(input())
word = input()
if char %2 == 1:
    print("No split can fit!")
    exit()
else:
    index = char // 2
    part1 = word[0:index]
    part2 = word[index:]
    if part1 == part2:
        print("Happy Birthday!")
    elif part1 == part2[::-1]:
        print("Happy Birthday!")
    else:
        print("No split can fit!")