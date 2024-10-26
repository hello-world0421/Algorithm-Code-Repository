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
    s = si()
    if s == '0' * s.count('0') + '1' * s.count('1'):
        ans.append(1)
    elif '01' in s:
        pass

sys.stdout.write('\n'.join(map(str, ans)))