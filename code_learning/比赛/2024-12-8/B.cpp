# B题
#include <bits/stdc++.h>

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(n);
    std::vector<bool> b(m, false);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0, t; i < m; i++) {
        std::cin >> t; t--;
        b[t] = true;
    }
    std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());
    for (int i = 0; i < n; i++) {
        if (b[a[i].second]) {
            continue;
        } else {
            std::cout << a[i].second + 1 << '\n';
            return;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}