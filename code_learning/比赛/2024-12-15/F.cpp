#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<bool> visit(n, false);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) dp[1][i] = i * a[i];
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}