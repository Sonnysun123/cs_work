n,l,r = map(int,input().split())
a = list(map(int,input().split()))
print(a)
a_rev = a[0:l-1]+a[len(a) - (r-1): l-2:-1]+a[r:]
print(*a_rev)