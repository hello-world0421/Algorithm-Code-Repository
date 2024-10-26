# 二进制题，遇到二进制不要动不动就用字符串，多尝试使用位运算构造二进制的解法
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
    a = []
    for i in range(62, -1, -1):
        x = 1 << i
        if (x & n) == x and n != x:
            a.append(n - x)
    a.append(n)
    ans.append(str(len(a)))
    ans.append(' '.join(map(str, a)))

sys.stdout.write('\n'.join(ans))