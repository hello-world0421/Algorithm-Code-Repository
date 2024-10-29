#include <bits/stdc++.h>

void solve() {
    int n, cnt = 0; std::cin >> n;
    for (int i = 1, a; i <= n; i++) {
        std::cin >> a;
        if (a & 1) cnt++;
    }
    std::cout << ((cnt & 1) ? "NO" : "YES") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}