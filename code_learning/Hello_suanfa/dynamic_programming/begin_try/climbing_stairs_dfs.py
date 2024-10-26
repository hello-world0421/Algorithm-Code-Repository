def dfs(i: int) -> int:
    """搜索"""
    # 已知 dp[1] 和 dp[2] , 返回之
    if i == 1 or i == 2:
        return i
    # dp[i] = dp[i-1] + dp[i-2]
    count = dfs(i - 1) + dfs(i - 2)
    return count

def climbing_stairs_dfs(n: int) -> int:
    """爬楼梯：搜索"""
    return dfs(n)

print(climbing_stairs_dfs(5))

# 时间复杂度为 O(2^n)，指数阶属于爆炸式增长，而这样的时间复杂度是由 “重叠子问题” 导致的，故为提升算法效率，我们希望所有的重叠子问题都只被计算一次