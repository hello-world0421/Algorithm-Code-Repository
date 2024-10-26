import sys
from math import inf

ans = []
for _ in range(int(input())):
    n = int(input())
    x = [-inf] + list(map(int, input().split())) + [inf]
    a = [x[1] + 1]
    i = 1
    while (val := x[i + 1]) != inf:
        ex = 1
        while a[i-1] * ex + x[i] <= val:
            ex += 1
        else:
            a.append(a[i-1] * ex + x[i])
        i += 1
    else:
        a.append(x[i])
    ans.append(' '.join(map(str, a)))

sys.stdout.write('\n'.join(ans))
