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
    n, k, q = mi()
    a = li()
    b = li()
    v = []
    for _ in range(q):
        d = ii()


sys.stdout.write('\n'.join(map(str, ans)))