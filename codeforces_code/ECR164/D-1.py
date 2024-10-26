# import sys, os, io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

# n = int(input())
# mod = 998244353
# a = list(map(int, input().split()))
# a.sort()
# m = 0
# dp0 = [0] * (m + 1)
# dp0[0] = 1
# ans = 0
# for i in a:
#     dp = [0] * i + list(dp0)
#     for j in range(1, len(dp)):
#         c = max(i, (j + 1) >> 1)
#         ans += dp[j] * c % mod
#     for j in range(m + 1):
#         dp[j] = (dp[j] + dp0[j]) % mod
#     dp0 = dp
#     m += i
# ans %= mod
# print(ans)

import sys

n = int(input())
mod = 998244353
a = list(map(int, input().split()))
a.sort()
m = 0
dp0 = [0] * (m + 1)
dp0[0] = 1
ans = 0
for i in a:
    dp = [0] * i + dp0[:]
    for j in range(1, len(dp)):
        c = max(i, (j + 1) >> 1)
        ans += dp[j] * c % mod
    for j in range(m + 1):
        dp[j] = (dp[j] + dp0[j]) % mod
    dp0 = dp
    m += i
ans %= mod
print(ans)
