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
    x = ii()
    
    maxi = 0
    maxiy = 0
    
    for y in range(1, x):
        if gcd(x, y) + y > maxi:
            maxi = gcd(x, y) + y
            maxiy = y
    print(maxiy)
for _ in range(ii()):
    solve()