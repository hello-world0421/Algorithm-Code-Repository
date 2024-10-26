#include <bits/stdc++.h>

const std::string narek = "narek";

constexpr int MAXN = 1e3 + 1;

int n, m, ans;

std::string s[MAXN];

void solve() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> s[i];

    std::vector<int> dp(5, INT_MIN), tdp;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        tdp = dp;

        for (int j = 0, next, score; j < 5; j++) if (dp[j] != INT_MIN) {
            next = j, score = 0;

            for (int k = 0, ind; k < m; k++) {
                ind = narek.find(s[i][k]);
                if (ind == -1) continue;

                if (ind == next) {
                    next = (next + 1) % 5;
                    score++;
                } else score--;
            }

            tdp[next] = std::max(tdp[next], dp[j] + score);
        }

        dp = tdp;
    }

    ans = 0;
    for (int i = 0; i < 5; i++) if (dp[i] != INT_MIN)
        ans = std::max(ans, dp[i] - 2 * i);
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}