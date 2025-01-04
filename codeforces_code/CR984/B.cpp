#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<i64> res(k, 0);
    for (int i = 0, brand, cost; i < k; i++) {
        std::cin >> brand >> cost;
        res[brand - 1] += cost;
    }
    std::sort(res.begin(), res.end(), std::greater<i64>());
    i64 ans = 0;
    for (int i = 0; i < std::min(k, n); i++) {
        ans += res[i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}