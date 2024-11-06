#include <bits/stdc++.h>

void solve() {
    int a, b, x, y; std::cin >> a >> b >> x >> y;
    int minx = std::min(2 * x, y);
    int ans;
    if (a > b) {
        ans = x + (a - b - 1) * minx;
    } else if (a == b) {
        ans = x;
    } else {
        ans = x + (b - a) * minx;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}