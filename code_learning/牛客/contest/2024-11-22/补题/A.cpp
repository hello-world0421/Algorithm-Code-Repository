#include <bits/stdc++.h>

void solve() {
    int a1, a2, b1, b2; std::cin >> a1 >> b1 >> a2 >> b2;
    std::cout << (a1 * b1 < a2 * b2 ? "lz" : "gzy") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}