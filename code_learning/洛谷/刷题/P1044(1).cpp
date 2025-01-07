#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    std::function<int(int, int)> dfs = [&](int i, int j) {
        if (dp[i][j]) return dp[i][j];
        if (i == 0) return dp[i][j] = 1;
        int ans = dfs(i - 1, j + 1);
        if (j != 0) ans += dfs(i, j - 1);
        return dp[i][j] = ans;
    };
    std::cout << dfs(n, 0) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}