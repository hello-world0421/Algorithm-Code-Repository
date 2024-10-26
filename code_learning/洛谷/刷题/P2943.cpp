#include <bits/stdc++.h>

void solve() {
    int n, m; std::cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int dp[n + 1] = { -1 };
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = i - j + 1; k <= i; k++) {
                
            }
            dp[i] = min(dp[i], cnt * cnt + dp[i - j]);
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}