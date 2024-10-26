from collections import defaultdict
from math import inf
import sys

input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(str(x) + '\n')

def solve():
    coins = list(map(int, input().split()))
    amount = int(input())

    dp = defaultdict(int)
    dp[0] = 0

    for i in range(1, amount + 1):
        dp[i] = inf
        for coin in coins:
            if i >= coin:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    print(dp[amount]) if dp[amount] != inf else print(-1)

solve()