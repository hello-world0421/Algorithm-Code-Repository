#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int ordered = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == i + 1) ordered--;
        else break;
    }
    std::vector<double> query;
    for (int i = 0; i < m; i++) {
        int x; double p; std::cin >> x >> p;
        if (x >= ordered) query.push_back(p);
    }
    if (ordered <= 1) {
        std::cout << 1 << '\n';
        return;
    }
    double ok = 0, no = 1;
    for (auto p : query) {
        ok += no * p;
        no = 1 - ok;
    }
    std::cout << std::fixed << std::setprecision(10) << ok << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}