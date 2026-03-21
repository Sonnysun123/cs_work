testcase = int(input())
l = list(map(int, input().split()))
check = True
for i in range(testcase):
    list_sum = sum(l[0:testcase])+sum(l[testcase+1:])
    if list_sum%testcase !=0:
        check = False
        break
if check is True:
    print("ranged")
else:
    print("deranged")
