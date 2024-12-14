#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }
    int max = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first > max || a[i].second >= cnt) {
            cnt++;
            max = std::max(max, a[i].first);
        }
    }
    std::cout << cnt << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}