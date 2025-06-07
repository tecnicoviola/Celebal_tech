# the-minion-game.py
# Task: Stuart vs Kevin game based on substring starting letters

# Sample Input:
# BANANA
# Sample Output:
# Stuart 12

def minion_game(string):
    vowels = 'AEIOU'
    kevin_score = 0
    stuart_score = 0

    for i in range(len(string)):
        if string[i] in vowels:
            kevin_score += len(string) - i  # Vowel start
        else:
            stuart_score += len(string) - i  # Consonant start

    if kevin_score > stuart_score:
        print("Kevin", kevin_score)
    elif stuart_score > kevin_score:
        print("Stuart", stuart_score)
    else:
        print("Draw")

s = input("Enter string for the game: ").upper()
minion_game(s)
