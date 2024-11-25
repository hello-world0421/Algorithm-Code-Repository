#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    int case1 = 0, case2 = 0;
    for (int i = 0; i < n - 2; i++) {
        case1 ^= i; case2 ^= (i + 1);
    }
    i64 addLast = (1ll << 31) - 1;
    if (case1 != 0) {
        for (int i = 0; i < n - 2; i++) {
            std::cout << i << ' ';
        }
        case1 ^= addLast;
        std::cout << addLast << ' ' << case1 << '\n';
    } else {
        for (int i = 1; i <= n - 2; i++) {
            std::cout << i << ' ';
        }
        case2 ^= addLast;
        std::cout << addLast << ' ' << case2 << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}