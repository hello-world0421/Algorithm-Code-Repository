import sys
input = sys.stdin.readline
from heapq import *
#from math import *

for _ in range(int(input())):
    
    a, b, c = map(int, input().split())
    if a < b < c:
        print("STAIR")
    elif a < b > c:
        print("PEAK")
    else:
        print("NONE")