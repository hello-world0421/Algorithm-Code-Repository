from math import inf

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    ans = 0
    x, y = a.index(max(a)) + 1, a.index(min(a)) + 1
    x1, y1 = min(x, n - x + 1), min(y, n - y + 1)
    