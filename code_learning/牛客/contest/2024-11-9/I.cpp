#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<i64> a(n);
    for (i64& num : a) {
        std::cin >> num;
    }
    i64 ans = LLONG_MIN, mina = a[0];
    for (int i = 1; i < n; i++) {
        ans = std::max(ans, a[i] - mina);
        mina = std::min(mina, a[i]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}