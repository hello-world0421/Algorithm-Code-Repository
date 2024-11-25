#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 l, r, k; std::cin >> l >> r >> k;
    std::cout << std::max(r / k - l + 1, 0ll) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}