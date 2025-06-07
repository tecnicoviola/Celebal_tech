# write-a-function.py
# Task: Define a leap year checking function

# Sample Input:
# 2000
# Sample Output:
# True

def is_leap(year):
    # Leap if divisible by 4 and not by 100, unless divisible by 400
    return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)

year = int(input("Enter a year: "))
print(is_leap(year))
