# 数位 dp

count = 0
def generate_numbers(n, p):
    if n == 0:
        return 1 if int(str(count)) % p == 0 else 0

    dp = [[0 for _ in range(p)] for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        for j in range(1, p):
            for k in range(1, 10):
                dp[i][j] += dp[i - 1][(j * 10 + k) % p]
                dp[i][j] %= 999911659
    print(dp)
    return dp[n][0]

n, p = map(int, input().split())
print(generate_numbers(n, p))