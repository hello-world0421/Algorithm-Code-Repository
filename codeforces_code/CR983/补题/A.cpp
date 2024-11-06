#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    int a = 0;
    for (int i = 0, num; i < 2 * n; i++) {
        std::cin >> num;
        a += num;
    }
    std::cout << (a & 1) << ' ' << std::min(a, 2 * n - a) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}