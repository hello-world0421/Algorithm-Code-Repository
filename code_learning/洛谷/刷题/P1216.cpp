#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> dp1(n + 1, INT_MIN), dp2(n + 1, INT_MIN);
    std::cin >> dp1[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cin >> dp2[j];
        }
        for (int j = 1; j <= i; j++) {
            dp2[j] += std::max(dp1[j - 1], dp1[j]);
        }
        dp1 = dp2;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, dp1[i]);
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}