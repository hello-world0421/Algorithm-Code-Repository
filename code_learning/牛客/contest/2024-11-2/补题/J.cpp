#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, x; std::cin >> n >> x;
    x = std::abs(x);
    i64 ans = 0;
    for (i64 i = 0, a; i < n; i++) {
        std::cin >> a;
        if (x == 0) {
            break;
        }
        ans += a;
        x = std::abs(x - a);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}