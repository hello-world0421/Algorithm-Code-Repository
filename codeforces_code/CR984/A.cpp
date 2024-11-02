#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (std::abs(a[i] - a[i - 1]) != 5 && std::abs(a[i] - a[i - 1]) != 7) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
    return;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}