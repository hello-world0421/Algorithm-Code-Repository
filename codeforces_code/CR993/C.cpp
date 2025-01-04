#include <bits/stdc++.h>

void solve() {
    int m, a, b, c; std::cin >> m >> a >> b >> c;
    int ans = 0, first = m, second = m;
    // if (a > first) {
    //     ans += first; first = 0;
    // } else {
    //     ans += a; first -= a;
    // }
    // if (b > second) {
    //     ans += second; second = 0;
    // } else {
    //     ans += b; second -= b;
    // }
    ans += std::min(first, a); first = std::max(first - a, 0);
    ans += std::min(second, b); second = std::max(second - b, 0);
    ans += std::min(first + second, c);
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}