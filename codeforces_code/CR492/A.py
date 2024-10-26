# 动态规划求解，O(5n)的时间复杂度
from collections import defaultdict
from math import inf


cashes = [1, 5, 10, 20, 100]
n = int(input())

dp = defaultdict(int)
dp[0] = 0

for i in range(1, n + 1):
    dp[i] = inf
    for cash in cashes:
        if i >= cash:
            dp[i] = min(dp[i], dp[i - cash] + 1)
print(dp[n])