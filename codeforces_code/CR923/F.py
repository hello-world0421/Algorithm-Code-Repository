import sys
from math import inf, gcd, lcm
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
si = lambda: input()
yes = lambda: ans.append('YES')
no = lambda: ans.append('NO')
mod = 998244353

ans = []
for _ in range(int(input())):
    n, m = map(int, input().split())
    adj = {num: (0, 0) for num in range(1, n + 1)}
    for __ in range(m):
        u, v, w = map(int, input().split())
        adj[u] = (v, w)
        adj[v] = (u, w)
    

sys.stdout.write('\n'.join(ans))