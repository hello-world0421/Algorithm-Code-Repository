#include <bits/stdc++.h>
using i64 = unsigned long long;

void solve() {
    i64 k, a, b; std::cin >> k >> a >> b;
    std::vector<i64> va, vb;
    while (a > 0 || b > 0) {
        va.push_back(a % k);
        a /= k;
        vb.push_back(b % k);
        b /= k;
    }
    i64 ans = 0;
    for (int i = 0; i < va.size(); i++) {
        ans += std::pow(k, i) * ((va[i] + vb[i]) % k);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();
}