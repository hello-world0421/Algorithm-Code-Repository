#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::pair<int, int> a[3];
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i].first >> a[i].second;
        ans = std::min(ans, a[i].second * ((n + a[i].first - 1) / a[i].first));
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}