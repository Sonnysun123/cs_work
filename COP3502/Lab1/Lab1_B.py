#Input: Price of item and sales tax percentage
#Output: Total price rounded 2 decimal places
price=float(input("Enter the price of the item: "))
tax=float(input("Enter the sales tax percentage: "))
total_price=price+price*0.01*tax
print(f"Your total is ${total_price:.2f}")