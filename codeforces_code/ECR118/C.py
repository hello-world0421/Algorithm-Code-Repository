from bisect import bisect_left
from math import *

def diff_ls(n, a):
    l = [0]
    for i in range(1, n):
        l.append(a[i] - a[i - 1])
    return sorted(l)

def cal_step(n, h, a):
    l = diff_ls(n, a)
    total = [0]
    for i in range(1, n):
        total.append(total[-1] + (l[i] - l[i - 1]) * (n - i + 1))

    print(f"total:{total}")
    nb = bisect_left(total, x=h) - 1
    tt_lower = total[nb]
    k = l[nb] + ceil((h - tt_lower) / (n - nb))
    return k

t = int(input())
for i in range(t):
    n, h = [int(_) for _ in input().split()]
    a = [int(_) for _ in input().split()]
    print(cal_step(n, h, a))
