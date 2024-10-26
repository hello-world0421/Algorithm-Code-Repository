import sys
from math import inf

n = int(input())
matrix = [[0] * n for _ in range(n)]
ans = -inf
for i in range(n):
    data = list(map(int, input().split()))
    if i == 0:
        matrix[0][0] = data[0]
    else:
        matrix[i][0] = data[0] + matrix[i - 1][0]
    for j in range(1, n):
        if i == 0:
            matrix[i][j] = data[j] + matrix[i][j - 1]
        else:
            matrix[i][j] = data[j] + matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1]
for i in range(n):
    