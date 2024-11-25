#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; i64 h; std::cin >> n >> h;
    std::vector<i64> a(n + 1, 0);
    i64 ans = -1, l = 1, r = h, mid;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](i64 power) {
        i64 ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += std::min(power, (i == n ? LLONG_MAX : a[i + 1] - a[i]));
        }
        return ans >= h;
    };

    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid; r = mid - 1;
        } else {
            l = mid + 1;
        }
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