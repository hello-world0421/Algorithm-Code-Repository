#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 x, y, k; std::cin >> x >> y >> k;
    i64 ans = (std::max(x, y) + k - 1) / k * 2;
    if ((std::min(x, y) + k - 1) / k < (ans >> 1)) {
        ans -= (x > y);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}