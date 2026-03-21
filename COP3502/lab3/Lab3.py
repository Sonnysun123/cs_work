import math
calc_num=0
curr_result=0.0
total=0.0
avg=0.0
print(f'Current Result: {curr_result}\n')
while True:
    print("Calculator Menu\n---------------\n0. Exit Program\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Logarithm\n7. Display Average\n")
    while True:
        selection = int(input("Enter Menu Selection: "))
        if selection==0:
            break
        elif selection==1:
            first=input("Enter first operand: ")
            second=input("Enter second operand: ")
            first=curr_result if first=="RESULT" else float(first)
            second=curr_result if second=="RESULT" else float(second)
            curr_result=first+second
            print(f"Current Result: {curr_result}\n")
            calc_num+=1
            total+=curr_result
            break
        elif selection==2:
            first = input("Enter first operand: ")
            second = input("Enter second operand: ")
            first = curr_result if first == "RESULT" else float(first)
            second = curr_result if second == "RESULT" else float(second)
            curr_result=first-second
            print(f"Current Result: {curr_result}\n")
            calc_num+=1
            total+=curr_result
            break
        elif selection==3:
            first = input("Enter first operand: ")
            second = input("Enter second operand: ")
            first = curr_result if first == "RESULT" else float(first)
            second = curr_result if second == "RESULT" else float(second)
            curr_result=first*second
            print(f"Current Result: {curr_result}\n")
            calc_num+=1
            total+=curr_result
            break
        elif selection==4:
            first = input("Enter first operand: ")
            second = input("Enter second operand: ")
            first = curr_result if first == "RESULT" else float(first)
            second = curr_result if second == "RESULT" else float(second)
            curr_result=first/second
            print(f"Current Result: {curr_result}\n")
            calc_num+=1
            total+=curr_result
            break
        elif selection==5:
            first = input("Enter first operand: ")
            second = input("Enter second operand: ")
            first = curr_result if first == "RESULT" else float(first)
            second = curr_result if second == "RESULT" else float(second)
            curr_result=math.pow(first,second)
            print(f"Current Result: {curr_result}\n")
            calc_num+=1
            total+=curr_result
            break
        elif selection==6:
            first = input("Enter first operand: ")
            second = input("Enter second operand: ")
            first = curr_result if first == "RESULT" else float(first)
            second = curr_result if second == "RESULT" else float(second)
            curr_result=math.log(second,first)
            print(f"Current Result: {curr_result}\n")
            calc_num+=1
            total+=curr_result
            break
        elif selection==7:
            if calc_num==0:
                print("Error: No calculations yet to average!\n")
            else:
                avg=total/calc_num
                print(f"Sum of calculations: {total:.2f}")
                print(f"Number of calculations: {calc_num}")
                print(f"Average of calculations: {avg:.2f}\n")
        else:
            print("Error: Invalid selection!\n")
    if selection==0:
        break
print("Thanks for using this calculator. Goodbye!")