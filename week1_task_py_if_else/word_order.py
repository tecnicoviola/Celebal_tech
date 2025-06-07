# word-order.py
# Task: Count unique words in the order they appear

# Sample Input:
# 4
# bcdef
# abcdefg
# bcde
# bcdef
# Sample Output:
# 3
# 2 1 1

from collections import OrderedDict

n = int(input("Enter number of words: "))
word_counts = OrderedDict()

# Count occurrences while preserving input order
for _ in range(n):
    word = input()
    word_counts[word] = word_counts.get(word, 0) + 1

print(len(word_counts))  # Unique word count
print(*word_counts.values())  # Frequencies
