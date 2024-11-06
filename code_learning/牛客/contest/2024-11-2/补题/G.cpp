#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    int ans = INT_MAX;
    for (int i = 0, count, cost; i < 3; i++) {
        std::cin >> count >> cost;
        ans = std::min(ans, (n + count - 1) / count * cost);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}