protein_size, eq_pairs, query, group_size = map(int, input().split())
dict1 = {}
dict2 = {}
protein_name = input()
for i in range(eq_pairs):
    a, b = (input().split())
    dict1[a] = b
    dict2[b] = a

for i in range(query):
    #print("hi")
    #print("i is ", i)

    current = input()
   # print("current", current)
    store = []
    for j in range(protein_size-group_size+1):
        maybe = protein_name[j:group_size+j]
        #print(maybe)
        count = 0
        for k in range(group_size):
            if current[k] in dict1:
                if maybe[k] == current[k] or maybe[k] == dict1[current[k]]:
                    count += 1
            elif current[k] in dict2:
                if maybe[k] == current[k] or maybe[k] == dict2[current[k]]:
                    count += 1
            else:
                #print("count breaks")
                break
            if count == group_size:
                j = j +3
                store.append(maybe)
    distinct_store = set(store)
    print(len(distinct_store))