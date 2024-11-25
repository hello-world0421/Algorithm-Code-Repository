#include <bits/stdc++.h>

void solve() {
    int m, s, t; std::cin >> m >> s >> t;
    std::vector<std::array<int, 2>> dp(m + 4 * t + 1);
    std::queue<std::array<int, 3>> q;
    q.push({ m, 0, 0 });
    while (!q.empty()) {
        auto [i, si, ti] = q.back(); q.pop();
        std::cerr << i << '\n';
        if (ti < t) {
            q.push({ i, si + 17, ti + 1 });
            q.push({ i - 10, si + 60, ti + 1 });
            q.push({ i + 4, si, ti + 1 });
        }
        dp[i] = { si, ti };
    }
    // for (int i = 0; i <= m; i++) {
    //     std::cerr << dp[i][0] << ' ' << dp[i][1] << '\n';
    // }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}