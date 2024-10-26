#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 a, b, v; std::cin >> a >> b >> v;
    std::cout << (v - (b << 1) + a - 1) / (a - b) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}