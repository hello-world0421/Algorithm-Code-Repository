#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n; std::cin >> n;
    std::pair<i64, i64> a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }
    i64 q; std::cin >> q;
    for (int i = 0; i < q; i++) {
        i64 type, date;
        std::cin >> type >> date; type--;
        if (date <= a[type].second) {
            std::cout << a[type].second << '\n';
        } else {
            i64 temp = (date - a[type].second) / a[type].first + 1;
            std::cout << a[type].second + temp * a[type].first << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt = 1;
    while (tt--)
        solve();

    return 0;
}