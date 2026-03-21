unit1=input("Enter the unit you are converting from: ")
unit2=input("Enter the unit you are converting to: ")
temp1 = float(input(f"Enter the temperature in {unit1}: "))
if unit1==unit2:
    temp2=temp1
else:
    if unit1=="Fahrenheit":
        if unit2=="Celsius":
            temp2=(temp1-32)*5/9
        else:
            temp2=(temp1-32)*5/9+273.15
    elif unit1=="Celsius":
        if unit2=="Fahrenheit":
            temp2=temp1*9/5+32
        else:
            temp2=temp1+273.15
    else:
        if unit2=="Celsius":
            temp2=temp1-273.15
        else:
            temp2=(temp1-273.15)*9/5+32
print(f"That is {temp2:.1f} degrees {unit2}.")
