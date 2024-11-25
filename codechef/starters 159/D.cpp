#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 1e9 + 7;

i64 quickPower(i64 a, i64 k) {
    i64 ans = 1;
    while (k > 0) {
        if (k & 1) {
            ans = ans * a % mod;
        }
        k >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void solve() {
    i64 n, d; std::cin >> n >> d;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (n == 1 && a[0] == 1) {
        std::cout << (1 - (1 + d) * quickPower(2 * d, mod - 2) % mod + mod) % mod << '\n';
    } else {
        std::cout << (1 + d) * quickPower(2 * d, mod - 2) % mod << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}