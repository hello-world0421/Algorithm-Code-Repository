import sys, time, random
from collections import deque, Counter, defaultdict
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
inf = 2 ** 61 - 1
mod = 998244353
from math import gcd
def solve():
    n = ii()
    x = li()
    a = [501]
    
    for i in range(n - 1):
        a.append(a[-1] + x[i])
        
    for i in range(n - 1):
        assert a[i + 1] % a[i] == x[i]
    print(*a)
for _ in range(ii()):
    solve()
