# compress-the-string.py
# Task: Count and compress consecutive characters

# Sample Input:
# 1222311
# Sample Output:
# (1, 1) (3, 2) (1, 3) (2, 1)

from itertools import groupby

s = input("Enter string to compress: ")

for k, g in groupby(s):
    print(f"({len(list(g))}, {k})", end=' ')

