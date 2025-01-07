#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int ans = 0, res = 0, t = 1;
    for (int i = 0; i < n; i++) {
        res += a[i];
        while (res > t * t) t += 2;
        if (res == t * t) {
            ans++; t += 2;
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