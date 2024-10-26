import sys
input = sys.stdin.readline
from collections import deque
from bisect import bisect_left, bisect_right
from heapq import *
#from math import *

for _ in range(int(input())):
    
    n = int(input())
    xrr = list(map(int, input().split()))
    arr = [0]*(n)
    arr[0] = 501
    for i in range(n-1):
        arr[i+1] = arr[i]+xrr[i]
    print(*arr)
