#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; i++)
        std::cin >> a[i][0];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][1];
        if (a[i][0] > a[i][1]) std::swap(a[i][0], a[i][1]);
    }
    int ans = 0, max = INT_MIN, max_index = -1;
    for (int i = 0; i < n; i++) {
        ans += a[i][1];
        if (a[i][0] > max) {
            max = a[i][0]; max_index = i;
        }
    }
    std::cout << ans + a[max_index][0] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}