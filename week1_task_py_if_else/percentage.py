# finding-the-percentage.py
# Task: Find average score of a student

# Sample Input:
# 3
# Krishna 67 68 69
# Arjun 70 98 63
# Malika 52 56 60
# Malika
# Sample Output:
# 56.00

n = int(input("Enter number of students: "))
student_marks = {}

# Input student name and scores
for _ in range(n):
    line = input("Enter name and marks: ").split()
    name = line[0]
    scores = list(map(float, line[1:]))
    student_marks[name] = scores

query_name = input("Enter name to find average: ")
average = sum(student_marks[query_name]) / len(student_marks[query_name])
print(f"{average:.2f}")
