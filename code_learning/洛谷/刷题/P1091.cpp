#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto process = [&](std::vector<int>& dp) {
        std::vector<int> ends;
        for (int i = 0; i < n; i++) {
            auto it = std::lower_bound(ends.begin(), ends.end(), a[i]);
            if (it == ends.end()) {
                ends.push_back(a[i]);
                dp[i] = ends.size();
            } else {
                *it = a[i];
                dp[i] = it - ends.begin() + 1;
            }
        }
    };

    std::vector<int> dp1(n, 1), dp2(n, 1);

    process(dp1);
    std::reverse(a.begin(), a.end());
    process(dp2);
    std::reverse(dp2.begin(), dp2.end());

    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, dp1[i] + dp2[i] - 1);
    }

    std::cout << n - ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}