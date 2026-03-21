testcase = int(input())
b = []
check = True
end = False
target = ""
for i in range(testcase):
    a = input()
    for word in b:
        if a == word:
            target = a
            end = True
            break
    if end:
        break
    b.append(a)

if end:
    print(target)
else:
    print("NO ECHOES SPOTTED")