#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n; std::cin >> n;
    std::cout << ((n & 1) ? (n * n >> 1) + 2 : 2) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}