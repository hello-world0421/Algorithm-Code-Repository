from math import inf


def cut_rod(p: list[int], n: int) -> int:
    """时间复杂度：O(2^n)"""
    if n == 0:
        return 0
    ans = -inf
    for i in range(1, n+1):
        ans = max(ans, p[i] + cut_rod(p, n-i))
    return ans


def memoized_cut_rod(p, n):
    r = [0] + [-inf] * n
    return memoized_cut_rod_aux(p, n, r)


def memoized_cut_rod_aux(p, n, r):
    if r[n] >= 0:
        return r[n]
    t = -inf
    for i in range(1, n+1):
        t = max(t, p[i] + memoized_cut_rod_aux(p, n - i, r))
    r[n] = t
    return r[n]


def bottom_up_cut_rod(p, n):
    r = [0] + [-inf] * n
    for i in range(1, n + 1):
        t = -inf
        for j in range(1, i+1):
            t = max(t, p[j] + r[i - j])
        r[i] = t
    return r[n]


def extended_bottom_up_cut_rod(p, n):
    r = [0] + [-inf] * n
    s = {}
    for i in range(1, n + 1):
        t = -inf
        for j in range(1, i + 1):
            if t < p[j] + r[i - j]:
                t = p[j] + r[i - j]
                s[i] = j
        r[i] = t
    return s, r


def print_cut_rod_solution(p, n):
    s, r = extended_bottom_up_cut_rod(p, n)
    print(f"最优解为：{r[n]}")
    print("方案为：", end='')
    while n > 0:
        print(s[n], end=' ')
        n -= s[n]


def print_all_cut_rod_solution(p, n):
    for i in range(1, n + 1):
        print(f"当 n 为 {i} 时：")
        print_cut_rod_solution(p, i)
        print('\n')


def static_cost_cut_rod(p, c, n):
    r = [0] + [-inf] * n
    s = {}
    for i in range(1, n + 1):
        t = -inf
        for j in range(1, i):
            if t < p[j] + r[i - j] - c:
                t = p[j] + r[i - j] - c
                s[i] = j
        if t < p[i]:
            t = p[i]
            s[i] = i
        r[i] = t
    return s, r


def print_static_cost_cut_rod_solution(p, c, n):
    s, r = static_cost_cut_rod(p, c, n)
    print(f"最优解为：{r[n]}")
    print("方案为：", end='')
    while n > 0:
        print(s[n], end=' ')
        n -= s[n]


def print_all_static_cost_cut_rod_solution(p, c, n):
    for i in range(1, n + 1):
        print(f"当 n 为 {i} 时：")
        print_static_cost_cut_rod_solution(p, c, i)
        print('\n')


def time_n_fibonacci(n):
    if n in (0, 1):
        return n
    dp = [0, 1] + [-inf] * (n - 1)
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]


def space_1_fibonacci(n):
    if n in (0, 1):
        return n
    last_last, last = 0, 1
    for i in range(2, n + 1):
        last_last, last = last, last_last + last
    return last


# 测试实例：
#    i: 1  2  3  4  5  6  7  8  9  10
# p[i]: 1  5  8  9  10 17 17 20 24 30
p0 = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
# print(bottom_up_cut_rod(p0, 7))
# print_cut_rod_solution(p0, 6)
# print_all_cut_rod_solution(p0, 10)
# print(static_cost_cut_rod(p0, 1, 7))
# print_all_static_cost_cut_rod_solution(p0, 2, 10)
print(time_n_fibonacci(1), space_1_fibonacci(1))
