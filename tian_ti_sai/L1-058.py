s = list(map(str, input().split()))
for i in range(len(s)):
    if 3 < s[i].count('6') <= 9:
        s[i] = '9'
    elif s[i].count('6') > 9:
        s[i] = '27'
print(' '.join(s))
