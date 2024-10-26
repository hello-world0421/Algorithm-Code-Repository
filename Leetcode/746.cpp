#include <bits/stdc++.h>
using namespace std;

// dp[i] 表示到 i 位置的最小花费
int minCostClimbingStairs1(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
        dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
    return dp[n];
}

// dp[i] 表示从 i 位置出发的最小花费
int minCostClimbingStairs2(vector<int>& cost) {
    int n = cost.size();
    cost.push_back(0);
    int lastlast, last, now;
    lastlast = cost[0], last = cost[1];
    for (int i = 2; i <= n; i++) {
        now = cost[i] + min(last, lastlast);
        lastlast = last, last = now;
    }
    return now;
}