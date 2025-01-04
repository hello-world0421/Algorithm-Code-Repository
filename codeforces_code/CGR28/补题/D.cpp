/*
贪心
时间复杂度：O(nlogn + mlogm)
*/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a, b;
    int x; std::cin >> x; a.push_back(x);
    for (int i = 1; i < n; i++) {
        std::cin >> x;
        if (x >= a[0]) a.push_back(x);
    }
    n = a.size();
    for (int i = 0; i < m; i++) {
        std::cin >> x;
        if (x > a[0]) b.push_back(x);
        else b.push_back(INT_MAX);
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::greater<int>());
    std::vector<i64> c(m);
    for (int i = 0, j = 0; i < m; i++) {
        while (b[i] <= a[j]) j++;
        c[i] = j;
    }
    for (int i = 1; i <= m; i++) {
        i64 ans = 0;
        for (int j = i - 1; j < m; j += i) {
            ans += c[j] + 1;
        }
        std::cout << ans << " \n"[i == m];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int _; std::cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}