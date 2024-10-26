import sys
from math import inf

ans = []
for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [inf] + list(map(int, input().split()))
    b = [inf] + list(map(int, input().split()))
    dp = [0 for _ in range(n+1)]
    dp[0] = inf
    dp[n] = a[n-1]
    for i in range(n - 1, -1, -1):
        dp[i] = min(dp[j] + sum(b[i+1:j]) for j in range(i + 1, n + 1))
    ans.append(min(dp[1:m+1]))
sys.stdout.write('\n'.join(map(str, ans)))