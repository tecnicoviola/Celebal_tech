# py-if-else.py
# Task: Print "Weird" or "Not Weird" based on conditions

# Sample Input:
# 3
# Sample Output:
# Weird

n = int(input("Enter a number: "))  # Read integer from user

if n % 2 != 0:
    print("Weird")  # Odd numbers are Weird
elif 2 <= n <= 5:
    print("Not Weird")  # Even and in range 2-5
elif 6 <= n <= 20:
    print("Weird")  # Even and in range 6-20
else:
    print("Not Weird")  # Even and greater than 20
