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

s = input()
k = 0
for c in set(s):
    if s.count(c) & 1 != 0:
        k += 1
if k in (0, 1):
    ans = 'First'
elif k & 1 == 0:
    ans = 'Second'
else:
    ans = 'First'

sys.stdout.write(ans)