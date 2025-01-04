#include <bits/stdc++.h>

constexpr int mod = 10;
constexpr int MAXN = 1e6 + 2;
std::vector<int> dp(MAXN);

void init() {
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
}

void solve() {
    int n; std::cin >> n;
    std::cout << dp[n] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    init();
    for (int i = 0; i < 100; i++) {
        std::cerr << i << ':' << dp[i] << '\n';
    }
    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}