import sys
input = sys.stdin.readline
from heapq import *
#from math import *

for _ in range(int(input())):
    
    n = int(input())
    a, b = {}, {}
    c, d = 0, 0
    songs = [input().split() for _ in range(n)]
    for song in songs:
        if song[0] not in a:
            a[song[0]] = c
            c += 1
        song[0] = a[song[0]]
        if song[1] not in b:
            b[song[1]] = d
            d += 1
        song[1] = b[song[1]]
    dp = [[0]*n for _ in range(1<<n)]
    for j in range(n):
        dp[1<<j][j] = 1
    for bit in range(1, 1<<n):
        for i in range(n):
            if not (bit&(1<<i)): continue
            for j in range(n):
                if (bit&(1<<j)): continue
                if songs[i][0] != songs[j][0] and songs[i][1] != songs[j][1]: continue
                dp[bit|(1<<j)][j] = max(dp[bit|(1<<j)][j], dp[bit][i] + 1)
    mx = 0
    for i in range(1<<n):
        mx = max(mx, max(dp[i]))
    print(n - mx)
