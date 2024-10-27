#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<i64, int>> x(n + 1);
    i64 pre = 0, suf = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> x[i].first;
        x[i].second = i;
        suf += x[i].first;
    }
    std::sort(x.begin(), x.end());
    std::vector<i64> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        pre += x[i].first;
        suf -= x[i].first;
        ans[x[i].second] = n + x[i].first * (2 * i - n) - pre + suf;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}