#task3
#Print the calendar of a given month and year
import calendar
print("enter a month")
m= int(input())
print("enter a year")
y= int(input())
if m>=1 and m<=12:
    print(calendar.month(y,m))
else:
    print("Invalid month. Please enter a value between 1 and 12.")    