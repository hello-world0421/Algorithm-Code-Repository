# import sys, os, io
# # input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

# t = int(input())
# ans = []
# for _ in range(t):
#     n, m, k = map(int, input().split())
#     c = n // m + min(n % m, 1)
#     ans0 = "YES" if n - c > k else "NO"
#     ans.append(ans0)
# sys.stdout.write("\n".join(ans))

# import sys, time, random
# from collections import deque, Counter, defaultdict
# input = lambda: sys.stdin.readline().rstrip()
# ii = lambda: int(input())
# mi = lambda: map(int, input().split())
# li = lambda: list(mi())
# inf = 2 ** 61 - 1
# mod = 998244353

# def solve():
#     n, m, k = mi()
#     mini = (n + m - 1) // m
#     if n - mini <= k or m == 1:
#         print('NO')
#     else:
#         print('YES')
    
    
# for _ in range(ii()):
#     solve()

import sys


ans = []
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    one_color_max_num = n // m + (n % m > 0)
    ans0 = "YES" if n - one_color_max_num > k else "NO"
    ans.append(ans0)
sys.stdout.write('\n'.join(ans))

def solve():
    n, m, k = map(int, input().split())
    mini = (n + m - 1) // m
    if n - mini <= k or m == 1:
        print('NO')
    else:
        print('YES')

t = int(input())
for _ in range(t):
    solve()
