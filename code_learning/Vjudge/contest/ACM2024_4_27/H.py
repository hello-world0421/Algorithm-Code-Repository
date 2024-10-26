from re import match
import sys

ans = []
n = int(input())
a = list(map(int, input().split()))
m = int(input())
for _ in range(m):
    x, y = map(int, input().split())
    match x:
        case 0:
            a[y-1] = a[y-2] + a[y] - a[y-1]
        case 1 if y == 1:
            ans.append(str(max(a) - min(a)))
        case 1:
            pass
