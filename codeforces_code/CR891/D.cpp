#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        b[i].first = a[i].first - a[i].second;
        b[i].second = i;
    }
    sort(b.begin(), b.end(), std::greater<std::pair<int, int>>());
    int cnt = 0;
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (b[i].first == b[0].first) {
            cnt++;
            ans.push_back(b[i].second + 1);
        } else {
            break;
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
        std::cout << ans[i] << " \n"[i == cnt - 1];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}