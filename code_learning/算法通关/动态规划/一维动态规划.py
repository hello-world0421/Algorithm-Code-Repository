def fibonacci1(n: int) -> int:
    """标准形式，时间复杂度 O(2^n) """
    if n == 0 or n == 1:
        return n
    return fibonacci1(n-1) + fibonacci1(n-2)


def fib2(n: int) -> int:
    """记忆化搜索，时间复杂度 O(n) """
    if n == 0 or n == 1:
        return n
    dp = [-1] * (n+1)
    dp[0], dp[1] = 0, 1
    return fibonacci2(n, dp)


def fibonacci2(n: int, dp: list) -> int:
    """记忆化搜索"""
    if dp[n] != -1:
        return dp[n]
    dp[n] = fibonacci2(n-1, dp) + fibonacci2(n-2, dp)
    return dp[n]


def fib3(n: int) -> int:
    """动态规划"""
    if n == 0 or n == 1:
        return n
    dp = [0] * (n+1)
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]


def fib4(n: int) -> int:
    """滚动数组"""
    if n == 1 or n == 0:
        return n
    last_last, last = 0, 1
    for _ in range(2, n+1):
        cur = last + last_last
        last_last = last
        last = cur
    return last


print(fib4(10))
