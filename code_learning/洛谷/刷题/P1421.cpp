#include <bits/stdc++.h>

void solve() {
    int a, b; std::cin >> a >> b;
    double money = a + b * 0.1;
    std::cout << (int)(money / 1.9) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}