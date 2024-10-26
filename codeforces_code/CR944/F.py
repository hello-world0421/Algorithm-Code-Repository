import sys
from math import inf, gcd, lcm, sqrt
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
    r = ii()
    n = 0
    for i in range(0, r+1):
        if 1 <= sqrt(1 + (i / r) ** 2) < 1 + 1 / r:
            if i == 0 or i == r:
                n += 4
                print(i)
            else:
                n += 8
                print(i)
    ans.append(n)
sys.stdout.write('\n'.join(map(str, ans)))