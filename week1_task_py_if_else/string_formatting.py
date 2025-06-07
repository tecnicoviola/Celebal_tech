# python-string-formatting.py
# Task: Print numbers in decimal, octal, hexadecimal, and binary

# Sample Input:
# 2
# Sample Output:
# 1 1 1 1
# 2 2 2 10

def print_formatted(number):
    width = len(bin(number)[2:])  # Width for alignment

    for i in range(1, number + 1):
        print(str(i).rjust(width),
              oct(i)[2:].rjust(width),
              hex(i)[2:].upper().rjust(width),
              bin(i)[2:].rjust(width))

n = int(input("Enter a number: "))
print_formatted(n)
