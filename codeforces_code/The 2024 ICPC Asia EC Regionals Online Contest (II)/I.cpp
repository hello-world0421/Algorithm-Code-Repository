#include <bits/stdc++.h>
using i64 = long long;

int n;

void solve() {
    std::cin >> n;
    if (!(n & 3)) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        int ans[32];
        for (int i = 0; i <= 31; i++) ans[i] = 1;

        for (int i = 0, next; i <= 30; i++) {
            next = n >> (i + 1) & 1;
            if (next == 0) ans[i] = -1;
        }
        if (!(n & 1)) ans[0] = 0;
        for (int i = 0; i <= 31; i++) {
            std::cout << ans[i] << " \n"[(i + 1) % 8 == 0];
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}