# K题
#include <bits/stdc++.h>

void solve() {
    int n, m; std::cin >> n >> m;
    if ((n & 1) || (m & 1)) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}