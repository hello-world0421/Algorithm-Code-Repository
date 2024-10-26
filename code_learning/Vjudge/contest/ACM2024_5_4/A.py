import sys
from math import inf

ans = []
for _ in range(int(input())):
    s = input()
    ans0 = []
    ans.append(str(len(s) - s.count('0')))
    i = 1
    while s:
        if s[-1] != '0':
            ans0.append(int(s[-1]) * i)
        s = s[:-1]
        i *= 10
    ans.append(' '.join(map(str, ans0)))

sys.stdout.write('\n'.join(ans))