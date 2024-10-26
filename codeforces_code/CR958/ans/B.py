# 模拟题，找规律，通过寻找可行解的特征来完备的刻画可行解
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
    n = int(input())
    s = input()
    ok = False
    if s.count('111') >= 1:
        ok = True
    elif s.count('11') >= 2:
        ok = True
    elif (s[0] == '1' or s[-1] == '1') and s.count('11') >= 1:
        ok = True
    elif s[0] == s[-1] == '1':
        ok = True
    if ok:
        ans.append("Yes")
    else:
        ans.append("No")

sys.stdout.write('\n'.join(ans))