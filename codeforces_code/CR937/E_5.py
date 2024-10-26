import sys
input = sys.stdin.readline
from heapq import *
#from math import *

for _ in range(int(input())):
    
    n = int(input())
    s = input().strip()
    yak = []
    u = 1
    while u*u <= n:
        if n%u == 0:
            yak.append(u)
            yak.append(n//u)
        u += 1
    yak.sort()
    yak.pop()
    ans = n
    for b in yak:
        d = s[:b]*(n//b)
        dif = 0
        for i in range(n):
            if s[i] != d[i]: dif += 1
        if dif <= 1:
            ans = b
            break
        d = s[b:2*b]*(n//b)
        dif = 0
        for i in range(n):
            if s[i] != d[i]: dif += 1
        if dif <= 1:
            ans = b
            break        
    print(ans)
            