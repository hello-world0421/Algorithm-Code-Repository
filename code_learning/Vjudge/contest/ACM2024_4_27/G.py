import sys
from re import match

ans = []
n = int(input())
b = list(map(int, input().split()))
y = [(i, b[i-1]) for i in range(1, n+1)]
m = int(input())
for _ in range(m):
    op, *x = map(int, input().split())
    match op:
        case 0:
            a, b = x
            y.append((a, b))
        case 1:
            a = x.pop()
            ans.append(str(y[a-1][1]))
sys.stdout.write('\n'.join(ans))
