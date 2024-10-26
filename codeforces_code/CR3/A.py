s = list(input())
t = list(input())
s[0] = ord(s[0]) - ord('a') + 1; s[1] = int(s[1])
t[0] = ord(t[0]) - ord('a') + 1; t[1] = int(t[1])

ans1 = 0
ans2 = []

while s[0] != t[0] or s[1] != t[1]:
    ans1 += 1
    if s[0] < t[0] and s[1] < t[1]:
        s[0] += 1; s[1] += 1
        ans2.append('RU')
    elif s[0] < t[0] and s[1] > t[1]:
        s[0] += 1; s[1] -= 1
        ans2.append('RD')
    elif s[0] > t[0] and s[1] < t[1]:
        s[0] -= 1; s[1] += 1
        ans2.append('LU')
    elif s[0] > t[0] and s[1] > t[1]:
        s[0] -= 1; s[1] -= 1
        ans2.append('LD')
    elif s[0] == t[0] and s[1] > t[1]:
        s[1] -= 1
        ans2.append('D')
    elif s[0] == t[0] and s[1] < t[1]:
        s[1] += 1
        ans2.append('U')
    elif s[0] < t[0] and s[1] == t[1]:
        s[0] += 1
        ans2.append('R')
    elif s[0] > t[0] and s[1] == t[1]:
        s[0] -= 1
        ans2.append('L')
print(ans1, *ans2, sep='\n')