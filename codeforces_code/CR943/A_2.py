import sys
input = sys.stdin.readline
from math import *

A = [0] * 1001

for i in range(2, 1001) :
    cnt = 0
    for j in range(1, i) :
        n = gcd(i, j)+j
        if cnt < n : cnt = n ; A[i] = j

for _ in range(int(input())) :
    print(A[int(input())])