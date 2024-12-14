// K题
#include <bits/stdc++.h>

void solve() {
    int n, m; std::cin >> n >> m;
    std::cout << ((n & 1) || (m & 1) ? "Alice" : "Bob") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}