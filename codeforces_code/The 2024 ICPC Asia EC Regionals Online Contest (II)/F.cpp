#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 1e5 + 1;

int n;

i64 c;

void solve() {
    std::cin >> n;
    i64 score = 1500;
    for (int i = 1; i <= n; i++) {
        std::cin >> c;
        score += c;
        if (score >= 4000) {
            std::cout << i << '\n';
            return;
        }
    }
    std::cout << -1 << '\n';
    return;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}