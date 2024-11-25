#include <bits/stdc++.h>

void solve() {
    double p1, p2, p3, p4, p5; std::cin >> p1 >> p2 >> p3 >> p4 >> p5;
    double p6 = p1 + p2 + p3, p7 = p4 + p5;
    double ans = 1 - std::pow(p6, 10) - std::pow(p6, 9) * p7 * 10;
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}