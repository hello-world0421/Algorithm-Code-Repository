import sys
from math import inf, gcd, lcm
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
si = lambda: input()
# yes = lambda: ans.append('YES')
# no = lambda: ans.append('NO')
mod = 998244353

multy = False
ans = 0
t = 1
if multy:
    t = int(input())
for _ in range(t):
    n = int(input())
    a = [0] + list(map(int, input().split()))
    for i in range(1, n + 1):
        vis = [False for _ in range(n + 1)]
        vis[i] = True
        num = 1
        while not vis[a[i]]:
            num += 1
            i = a[i]
            vis[i] = True
        ans = max(ans, num)

sys.stdout.write(str(ans))