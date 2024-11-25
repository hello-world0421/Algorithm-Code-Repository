#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n; std::cin >> n;
    if (n == 1) {
        std::cout << 3 << '\n';
    } else if (n == 2) {
        std::cout << 5 << '\n';
    } else {
        n -= 3;
        std::cout << 7 + n % 3 + 4 * (n / 3) << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}