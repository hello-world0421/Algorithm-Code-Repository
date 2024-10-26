#include <bits/stdc++.h>

constexpr int MAXN = 5e4 + 1;
int stack[MAXN], arr[MAXN], pos[MAXN];
int n, r;

int main() {
    int temp, i = 0;
    while (std::cin >> temp)
        arr[i++] = temp;
    n = i;

    // 单调栈维护左侧离当前位置最近的且比它大的数的位置
    r = 0;
    int cur;
    // 遍历阶段
    for (int i = 0; i < n; i++) {
        while (r > 0 && arr[stack[r - 1]] <= arr[i]) {
            cur = stack[--r];
            pos[cur] = r > 0 ? stack[r - 1] : -1;
        }
        stack[r++] = i;
    }
    // 清算阶段
    while (r > 0) {
        cur = stack[--r];
        pos[cur] = r > 0 ? stack[r - 1] : -1;
    }

    // i : 表示当前位置的最大可能数
    // 可以维护离当前最近的且比它大的数的位置 (单调栈)
    int dp[n] = { INT_MIN }, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        dp[i] = (i == 0 || pos[i] == -1 ? 1 : std::max(1, dp[pos[i]] + 1));
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';

    auto check = [&](int limit) {
        for (int i = 0; i < n; i++) {
            
        }
        };

    return 0;
}