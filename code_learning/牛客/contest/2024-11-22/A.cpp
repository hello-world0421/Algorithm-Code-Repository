#include <bits/stdc++.h>

void solve() {
    int a, b, c, d; std::cin >> a >> b >> c >> d;
    std::cout << (a * b < c * d ? "lz" : "gzy");
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}