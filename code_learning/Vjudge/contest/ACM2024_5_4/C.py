import sys
from math import inf

ans = []
for _ in range(int(input())):
    n, k = map(int, input().split())
    if n % k == 0:
        ans.append('YES')
        ans.append(' '.join([str(n // k)] * k))
        continue
    if n < k:
        ans.append('NO')
        continue
    p1 , p2, p3 = n % 2, n - (k - 1) * 2, n - k + 1
    if p1 == 0 and p2 % 2 == 0 and p2 > 0:
        ans.append('YES')
        ans.append(' '.join(['2'] * (k - 1) + [str(p2)]))
    elif p1 == 1 and p3 % 2 == 1 and p3 > 0:
        ans.append('YES')
        ans.append(' '.join(['1'] * (k - 1) + [str(p3)]))
    elif p1 == 0 and p2 % 2 == 1 and p2 > 0:
        ans.append('NO')
    else:
        ans.append('NO')

sys.stdout.write('\n'.join(ans))