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


n, m = map(int, input().split())
res = 0
if n == 1:
    res = 1
elif m > n / 2:
    res = m - 1
else:
    res = m + 1
ans = str(res)

sys.stdout.write(ans)