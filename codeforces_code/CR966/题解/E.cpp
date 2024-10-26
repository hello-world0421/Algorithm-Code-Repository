#include <bits/stdc++.h>
using ll = long long;

void solve() {
    int n, m, k; std::cin >> n >> m >> k;
    int w; std::cin >> w;
    std::vector<ll> a(w);
    for (int i = 0; i < w; i++) {
        std::cin >> a[i];
    }
    std::vector<ll> f(n * m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int r = std::min(i, n - k + 1) - std::max(1, i - k + 1) + 1;
            int c = std::min(j, m - k + 1) - std::max(1, j - k + 1) + 1;
            f.push_back(r * c);
        }
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(f.begin(), f.end(), std::greater<int>());
    ll ans = 0;
    for (int i = 0; i < w; i++) {
        ans += a[i] * f[i];
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}