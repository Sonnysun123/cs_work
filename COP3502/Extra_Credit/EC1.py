def price_calc(adult_price, child_price):
    adult_ticket = int(input("Adult tickets:	"))
    child_ticket = int(input("  Kid tickets:	"))
    if adult_ticket + child_ticket <= 30:
        price = adult_price * adult_ticket + child_price * child_ticket
        print(f"Total cost:    ${price:.2f}")
    else:
        print(invalid)

print("Available movies today:")
print("A)12 Strong:	1)2:30	2)4:40	3)7:50	4)10:50")
print("B)Coco:	        1)12:40	2)3:45")
print("C)The Post:	1)12:45	2)3:35	3)7:05	4)9:55")

movie=input("Movie choice:   ")
invalid="Invalid option; please restart app..."
adult_before = 11.17
adult_after = 12.45
child_before = 8.00
child_after = 9.68
if movie == "A":
    time = input("Showtime:       ")
    if time == "1" or time == "2" or time == "3" or time == "4":
        adult_price = adult_after
        child_price = child_after
        price_calc(adult_price, child_price)
    else:
        print(invalid)

elif movie == "B":
    time = input("Showtime: 		")
    if time == "1" or time == "2":
        if time == "1":
            adult_price = adult_before
            child_price = child_before
        if time == "2":
            adult_price = adult_after
            child_price = child_after
            price_calc(adult_price, child_price)
    else:
        print(invalid)

elif movie == "C":
    time = input("Showtime: 		")
    if time == "1" or time == "2" or time == "3" or time == "4":
        if time == "1":
            adult_price = adult_before
            child_price = child_before
        else:
            adult_price = adult_after
            child_price = child_after
            price_calc(adult_price, child_price)
    else:
        print(invalid)

else:
    print(invalid)
