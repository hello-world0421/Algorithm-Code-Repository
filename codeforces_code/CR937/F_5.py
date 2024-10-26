import sys
input = sys.stdin.readline
from heapq import *
#from math import *

for _ in range(int(input())):
    
    a, b, c = map(int, input().split())
    if c != a+1:
        print(-1)
        continue
    if a == 0:
        print(b)
        continue
    h = 1
    u = 1
    rr = 2
    while u < a:
        u += rr
        rr *= 2
        h += 1
    gap = (u-a)
    b -= (u-a)
    rr //= 2
    rr = 2*(rr-gap)+gap
    while b > 0:
        b -= rr
        h += 1
    print(h)
    