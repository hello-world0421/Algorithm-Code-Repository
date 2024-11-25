#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; char x; std::cin >> n >> x;
    i64 ans = 0; std::string sn;
    for (int i = 1; i <= n; i++) {
        sn = std::to_string(i);
        ans += std::count(sn.begin(), sn.end(), x);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}