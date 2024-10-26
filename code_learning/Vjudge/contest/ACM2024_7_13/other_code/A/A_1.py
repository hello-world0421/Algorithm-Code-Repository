from collections import defaultdict
import sys

# 定义输入输出更快的方式
input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(str(x) + '\n')


def solve():
    # 读取输入
    n = int(input())
    t = list(map(int, input().split()))
    sum_t = sum(t)

    # 动态规划初始化
    dp = defaultdict(bool)
    dp[0] = True

    # 动态规划过程
    for num in t:
        new_dp = defaultdict(bool)
        for key in dp.keys():
            new_dp[key - num] = True
            new_dp[key + num] = True
        dp = new_dp
    print(dp)

    # 计算答案
    ans = float('inf')

    for key in dp.keys():
        tim = (sum_t + key) // 2
        ans = min(ans, max(tim, sum_t - tim))
    
    # 输出结果
    print(ans)

if __name__ == "__main__":
    # 解决问题
    t = 1
    # t = int(input())  # 如果有多个测试用例
    while t > 0:
        solve()
        t -= 1