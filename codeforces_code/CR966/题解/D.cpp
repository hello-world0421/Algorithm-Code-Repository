#include <bits/stdc++.h>
using ll = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<ll> a(n + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    std::string s; std::cin >> s;
    s = " " + s;
    int l = 1, r = n;
    ll ans = 0;
    while (l <= r) {
        while (s[l] != 'L') l++;
        while (s[r] != 'R') r--;
        if (r > l) {
            ans += pre[r] - pre[l - 1];
            l++, r--;
        }
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