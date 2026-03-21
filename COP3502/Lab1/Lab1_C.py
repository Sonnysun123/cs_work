'''Input 1: Year for date1
Input 2: month for date2
Input 3: day for date3
Input 4: year for date2
Input 5: month for date
Input 6: day for date3
output:The difference between {month1}/{day1}/{year1} and {month2}/{day2}/{year2} is {difference} days!
'''
year_1=int(input("Enter the year for date 1: "))
month_1=int(input("Enter the month for date 1: "))
day_1=int(input("Enter the day for date 1: "))
year_2=int(input("Enter the year for date 2: "))
month_2=int(input("Enter the month for date 2: "))
day_2=int(input("Enter the day for date 2: "))
difference=abs(360*(year_2-year_1)+30*(month_2-month_1)+1*(day_2-day_1))
print(f"The difference between {month_1}/{day_1}/{year_1} and {month_2}/{day_2}/{year_2} is {difference} days!")