#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    n %= 5;
    if (n == 2 || n == 3 || n == 4) {
        std::cout << 0 << '\n';
    } else if (n == 0) {
        std::cout << 2 << '\n';
    } else {
        std::cout << 1 << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}