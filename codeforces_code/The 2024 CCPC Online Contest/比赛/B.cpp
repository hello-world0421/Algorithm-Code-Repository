#include <bits/stdc++.h>
using i64 = unsigned long long;

constexpr int MAXN = 1e3 + 1;

constexpr int mod = 998'244'353;

i64 fac[MAXN];

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

void solve() {
    int n; std::cin >> n;
    init(n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    i64 res = 1;
    int cnt = 1;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += a[j] - a[i];
        }
        if (i > 0 && a[i] == a[i - 1]) {
            cnt++;
            if (cnt == n) flag = false;
        } else {
            res = res * fac[cnt] % mod;
            cnt = 1;
        }
    }
    res = res * fac[cnt] % mod * (n >= 2 && flag ? 2 : 1) % mod;
    std::cout << ans << ' ' << res;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}