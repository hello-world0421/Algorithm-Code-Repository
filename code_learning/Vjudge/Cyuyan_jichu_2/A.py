import operator
from functools import reduce

alphabet = {chr(i): i - ord('A') + 1 for i in range(ord('A'), ord('Z')+1)}
star_name = input()
team_name = input()

ans1 = reduce(operator.mul, (alphabet[char] for char in star_name))
ans2 = reduce(operator.mul, (alphabet[char] for char in team_name))

if ans1 % 47 == ans2 % 47:
    print("GO")
else:
    print("STAY")
