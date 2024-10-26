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
    a, b, c, d = mi()
    a, b = min(a, b), max(a, b)
    c, d = min(c, d), max(c, d)
    if ((c < a < d and b > d) or (c < b < d and a < c)):
        yes()
    else:
        no()

sys.stdout.write('\n'.join(map(str, ans)))