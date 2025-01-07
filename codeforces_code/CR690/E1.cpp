#include <bits/stdc++.h>
using i64 = long long;

i64 comb2(i64 n) {
    return n * (n - 1) / 2;
}

i64 comb3(i64 n) {
    return n * (n - 1) * (n - 2) / 6;
}

void solve() {
    int n; std::cin >> n;
    std::vector<i64> a(n + 1, 0);
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        a[x]++;
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 3) ans += comb3(a[i]);
        if (i + 1 <= n) {
            if (a[i] >= 2 && a[i + 1] >= 1) ans += comb2(a[i]) * a[i + 1];
            if (a[i] >= 1 && a[i + 1] >= 2) ans += a[i] * comb2(a[i + 1]);
        }
        if (i + 2 <= n) {
            if (a[i] >= 1 && a[i + 1] >= 1 && a[i + 2] >= 1) ans += a[i] * a[i + 1] * a[i + 2];
            if (a[i] >= 2 && a[i + 2] >= 1) ans += comb2(a[i]) * a[i + 2];
            if (a[i + 2] >= 2 && a[i] >= 1) ans += comb2(a[i + 2]) * a[i];
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}