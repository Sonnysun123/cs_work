income=float(input("Enter your total income this year: "))
tax=0
tier1=11600
tier2=47150
tier3=100525
tier4=191950
tier5=243725
tier6=609350
if income>=tier6:
    tax=0.37*(income-tier6)+0.35*(tier6-tier5)+0.32*(tier5-tier4)+0.24*(tier4-tier3)+0.22*(tier3-tier2)+0.12*(tier2-tier1)+0.10*tier1
elif tier5<=income<=tier6:
    tax=0.35*(income-tier5)+0.32*(tier5-tier4)+0.24*(tier4-tier3)+0.22*(tier3-tier2)+0.12*(tier2-tier1)+0.10*tier1
elif tier4<=income<=tier5:
    tax=0.32*(income-tier4)+0.24*(tier4-tier3)+0.22*(tier3-tier2)+0.12*(tier2-tier1)+0.10*tier1
elif tier3<=income<=tier4:
    tax=0.24*(income-tier3)+0.22*(tier3-tier2)+0.12*(tier2-tier1)+0.10*tier1
elif tier2<=income<=tier3:
    tax=0.22*(income-tier2)+0.12*(tier2-tier1)+0.10*tier1
elif tier1<=income<=tier2:
    tax=0.12*(income-tier1)+0.10*tier1
else:
    tax=0.10*income
print(f"You owe ${tax:.2f} this year.")