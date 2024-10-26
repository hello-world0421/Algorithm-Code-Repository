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
    n, m = mi()
    a = input()
    b = input()
    
    cnt = 0
    
    for i in range(m):
        if cnt == n:
            break
        if a[cnt] == b[i]:
            cnt += 1
    print(cnt)
for _ in range(ii()):
    solve()