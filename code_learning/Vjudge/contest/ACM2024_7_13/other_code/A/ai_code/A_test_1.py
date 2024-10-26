from typing import List

class CoinChange:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 初始化dp数组，大小为amount+1，因为要计算到amount本身
        dp = [float('inf')] * (amount + 1)
        # base case
        dp[0] = 0
        
        # 外层循环遍历所有金额
        for i in range(1, amount + 1):
            # 内层循环遍历所有硬币
            for coin in coins:
                if i >= coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        
        # 如果dp[amount]仍然是无穷大，说明没有解决方案
        return dp[amount] if dp[amount] != float('inf') else -1