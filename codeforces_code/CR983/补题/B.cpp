#include <bits/stdc++.h>

void solve() {
    int n, k; std::cin >> n >> k;
    if (n == 1) {
        std::cout << "1\n1\n";
    } else {
        if (k == 1 || k == n) {
            std::cout << "-1\n";
        } else {
            std::cout << "3\n1 ";
            int temp = std::min(k - 2, n - k - 1);
            std::cout << k - temp << ' ';
            std::cout << k + temp + 1 << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}