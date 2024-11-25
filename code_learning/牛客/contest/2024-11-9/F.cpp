#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    i64 sum = 0;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (n <= 2) {
        std::cout << -1 << '\n';
        return;
    }
    std::sort(a.begin(), a.end());
    std::cout << std::max(a[n / 2] * n * 2 + 1 - sum, 0ll) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}