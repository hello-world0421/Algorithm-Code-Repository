import sys
input = sys.stdin.readline
from collections import deque
from bisect import bisect_left, bisect_right
from heapq import *
#from math import *

for _ in range(int(input())):
    
    n, m = map(int, input().split())
    a = input().strip()
    b = input().strip()
    j = 0
    for i in range(len(a)):
        while j < len(b) and a[i] != b[j]:
            j += 1
        if j < len(b) and a[i] == b[j]:
            j += 1
        else:
            break
    else:
        print(len(a))
        continue
    print(i)