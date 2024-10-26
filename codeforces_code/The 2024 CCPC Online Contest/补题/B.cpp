#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 1e3 + 1;

constexpr int mod = 998'244'353;

int n, a[MAXN];

std::map<int, i64> mp;

i64 ans, cnt;

i64 fac[MAXN];

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = fac[i - 1] * i % mod;
}

void solve() {
    mp.clear();
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        mp[a[i]]++;
    }
    std::sort(a + 1, a + n + 1);

    ans = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += a[j] - a[i];
        }
    }
    int flag = 0;
    for (auto [a, c] : mp) {
        if (c > 0) flag++;
        cnt = cnt * fac[c] % mod;
    }
    if (flag >= 2) cnt = cnt * 2 % mod;

    std::cout << ans << ' ' << cnt << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    init();
    solve();

    return 0;
}