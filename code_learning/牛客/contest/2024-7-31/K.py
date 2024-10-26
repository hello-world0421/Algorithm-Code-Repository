from collections import Counter

n = int(input())
a = list(map(int, input().split()))
b = dict(Counter(a))
c = sorted(set(a))
d = {}
for i in range(len(c)):
    if i == 0:
        d[c[i]] = 0
    else:
        d[c[i]] = d[c[i - 1]] + b[c[i - 1]]
for num in a:
    print(d[num], end=' ')