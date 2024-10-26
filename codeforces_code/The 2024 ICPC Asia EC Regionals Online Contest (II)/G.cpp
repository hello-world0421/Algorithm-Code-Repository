#include <bits/stdc++.h>
using i64 = long long;

constexpr int mod = 998'244'353;

i64 x, y, a0, a1, t, p0, p1;

i64 quickPow(i64 a, i64 b) {
    i64 ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1; a = a * a % mod;
    }
    return ans;
}

i64 f(i64 x, i64 y) {
    if (x == y) {
        return p0;
    } else if (x > y) {
        return (p0 + p1 * f(x - y, y) % mod) % mod;
    } else {
        return p0 * f(x, y - x) % mod;
    }
}

void solve() {
    std::cin >> x >> y >> a0 >> a1 >> t;
    i64 t = quickPow(a0 + a1, mod - 2);
    p0 = a0 * t % mod;
    p1 = a1 * t % mod;
    std::cout << f(x, y) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}