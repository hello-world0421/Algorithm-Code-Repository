"""
利用循环节寻找规律求解该题，但是Python还是太慢了，依然过不了
"""
import sys
from math import ceil, log2
input = lambda: sys.stdin.readline().rstrip()
mod = 998244353

def func(x, k):
    T = 1 << (k + 1)
    val = T // 2
    x += 1
    res = x // T * val
    r = x % T
    r -= val
    if r > 0:
        res += r
    return res
dp = {}
for _ in range(int(input())):
    ans = 0
    l, r = map(int, input().split())
    log = ceil(log2(r))
    for i in range(log + 1):
        if (r, i) not in dp.keys():
            res1 = func(r, i)
            dp[(r, i)] = res1
        else:
            res1 = dp[(r, i)]
        if (l - 1, i) not in dp.keys():
            res2 = func(l - 1, i)
            dp[(l - 1, i)] = res2
        else:
            res2 = dp[(l - 1, i)]
        p = (res1 % mod - res2 % mod + mod) % mod
        ans = (ans + p) % mod
    sys.stdout.write(str(ans) + '\n')