#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n; std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 ans = LLONG_MAX, minPre = a[0];
    for (int j = 1; j < n; j++) {
        ans = std::min(ans, minPre - a[j]);
        minPre = std::min(minPre, a[j]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}