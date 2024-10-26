import sys
from math import inf

ans = []
for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())), reverse=True)
    if n == 1 and a[0] > 1:
        ans.append('NO')
    elif n == 1 and a[0] == 1:
        ans.append('YES')
    elif a[0] - a[1] > 1:
        ans.append('NO')
    else:
        ans.append('YES')

sys.stdout.write('\n'.join(ans))