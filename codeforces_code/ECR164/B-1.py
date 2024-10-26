# import sys, os, io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

# t = int(input())
# ans = []
# inf = pow(10, 9) + 1
# for _ in range(t):
#     n = int(input())
#     a = list(map(int, input().split()))
#     if min(a) == max(a):
#         ans0 = -1
#     elif a[0] ^ a[-1]:
#         ans0 = 0
#     else:
#         u = [-1]
#         for i in range(n):
#             if a[i] ^ a[0]:
#                 u.append(i)
#         u.append(n)
#         ans0 = inf
#         for i in range(len(u) - 1):
#             ans0 = min(ans0, u[i + 1] - u[i] - 1)
#     ans.append(ans0)
# sys.stdout.write("\n".join(map(str, ans)))

# import sys, time, random
# from collections import deque, Counter, defaultdict
# input = lambda: sys.stdin.readline().rstrip()
# ii = lambda: int(input())
# mi = lambda: map(int, input().split())
# li = lambda: list(mi())
# inf = 2 ** 61 - 1
# mod = 998244353

# def solve():
#     n = ii()
#     a = li()
#     if max(a) == min(a):
#         print(-1)
#         return
#     cnt = 0
#     that = a[0]
#     ans = inf
#     for i in range(n):
#         if a[i] == that:
#             cnt += 1
#         else:
#             ans = min(ans, cnt)
#             cnt = 0 
#     ans = min(ans, cnt)
#     print(ans)
    
    
# for _ in range(ii()):
#     solve()

import sys

t = int(input())
ans = []
inf = pow(10, 9) + 1
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if min(a) == max(a):
        ans0 = -1
    # elif a[0] ^ a[-1]:
    #     ans0 = 0
    else:
        u = [-1] + [i for i, x in enumerate(a) if x ^ a[0]] + [n]
        ans0 = min(u[i + 1] - u[i] - 1 for i in range(len(u) - 1))
    ans.append(ans0)

sys.stdout.write("\n".join(map(str, ans)))

inf = 2 ** 61 - 1
def solve():
    int(input())
    a = list(map(int, input().split()))
    if max(a) == min(a):
        print(-1)
        return
    cnt = 0
    that = a[0]
    ans = inf
    for val in a:
        if val == that:
            cnt += 1
        else:
            ans = min(ans, cnt)
            cnt = 0
    ans = min(ans, cnt)
    print(ans)

t = int(input())
for _ in range(t):
    solve()
