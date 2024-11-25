#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n, x, y, z, t; std::cin >> n >> x >> y >> z >> t;
    std::vector<std::pair<i64, i64>> a;
    for (int i = 0, f, g, price; i < n; i++) {
        std::cin >> f >> g >> price;
        a.push_back({ f + g, price });
    }
    i64 ans = x + y;
    for (int i = 0; i < n; i++) {
        if (a[i].first > ans && a[i].second <= t + z) {
            ans = a[i].first;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}