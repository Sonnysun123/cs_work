def fibonacci(x):
    first=0
    second=1
    value=first+second
    if x == 1:
        return first
    elif x == 2:
        return second
    else:
        for i in range(x-3):
            first=second
            second=value
            value=first+second
        return value

def is_prime(x):
    check=True
    if x<1:
        check=False
        return check
    elif 1<=x<=3:
        return check
    else:
        for i in range(2,x//2+1):
            if x%i==0:
                check=False
                break
        return check

def print_prime_factors(x):
    if is_prime(x):
        print(f"{x} = {x}")
    else:
        a=""
        print(f"{x} = ",end="")
        i=2
        while i<=x:
            while x%i==0:
                a=a+f"{i} * "
                x=x/i
            i+=1
        print(a[0:-3])

