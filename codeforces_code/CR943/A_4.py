import sys
input = sys.stdin.readline
from collections import deque
from bisect import bisect_left, bisect_right
from heapq import *
from math import *

for _ in range(int(input())):
    
    mx = 0
    my = -1
    x = int(input())
    for y in range(1, x):
        c = gcd(x, y)+y
        if c > mx:
            mx = c
            my = y
    print(my)