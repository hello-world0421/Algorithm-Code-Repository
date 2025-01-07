#include <bits/stdc++.h>

void solve() {
    int m, n; std::cin >> m >> n;
    std::cout << std::max(m, n) + 1 << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}