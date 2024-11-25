#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 h, k; std::cin >> h >> k;
    int ans = 0;
    for (i64 i = 2; i * i <= h; i++) {
        while (h % i == 0) {
            ans++; h /= i;
        }
    }
    if (h != 1) {
        ans++; h = 1;
    }
    h <<= 1;
    while (h <= k) {
        ans++; h <<= 1;
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