#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 k, l1, r1, l2, r2; std::cin >> k >> l1 >> r1 >> l2 >> r2;
    i64 ans = 0;

    for (int i = 0, kn = 1; i <= 32; i++) {
        if (r2 / kn < l1) break;
        ans += std::max(0LL, std::min(r2 / kn, r1) - std::max((l2 + kn - 1) / kn, l1) + 1);
        kn *= k;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}