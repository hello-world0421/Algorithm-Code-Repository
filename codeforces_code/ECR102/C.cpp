#include <bits/stdc++.h>

void solve() {
    int n, k; std::cin >> n >> k;
    int m = n - k;
    for (int i = 1; i <= k - m - 1; i++) {
        std::cout << i << ' ';
    }
    for (int i = k; i >= k - m; i--) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}