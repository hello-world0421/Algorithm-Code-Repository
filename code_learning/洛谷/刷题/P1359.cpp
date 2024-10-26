#include <bits/stdc++.h>

constexpr int MAXN = 201;

int n;

int adj[MAXN][MAXN];

int dp[MAXN];

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            std::cin >> adj[i][j];

    for (int i = 1; i <= n; i++)
        dp[i] = INT_MAX;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = i - 1; j >= 1; j--)
            dp[i] = std::min(dp[i], dp[j] + adj[j][i]);

    std::cout << dp[n] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}