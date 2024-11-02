#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, x; std::cin >> n >> x;
    x = std::abs(x);
    i64 a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (x == 0) {
            break;
        } else {
            ans += a[i];
            x = std::abs(x - a[i]);
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}