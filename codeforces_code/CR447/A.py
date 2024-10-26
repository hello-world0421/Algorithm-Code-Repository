s = list(input())
ans = 0
while s.count('A') != 0:
    i = s.index('A')
    ans += s[:i].count('Q') * s[i:].count('Q')
    s.pop(i)
print(ans)
