#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 1e9 + 7;

i64 fac[400], inv[400];

i64 quickPower(int a, int k) {
    i64 ans = 1;
    while (k > 0) {
        if (k & 1) {
            ans = ans * a % mod;
        }
        k >>= 1;
    }
    return ans;
}

void pre() {
    fac[0] = 1;
    for (int i = 1; i <= 307; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    i64 invFac = quickPower(fac[307], mod - 2);
    for (int i = 307; i >= 1; i--) {
        inv[i] = fac[i - 1] * invFac % mod;
        invFac = invFac * i % mod;
    }
}

void solve(int n) {
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (fac[3 * i + 6] % (3 * i + 7) + 1) * inv[3 * i + 7] % mod;
    }
    std::cout << n << ':' << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    pre();
    for (int i = 1; i < 10; i++) {
        std::cerr << inv[i] << '\n';
    }

    // int tt; std::cin >> tt;
    // while (tt--)
    for (int i = 1; i <= 100; i++)
        solve(i);
}