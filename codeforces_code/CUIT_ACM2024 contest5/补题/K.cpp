#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, int b, int MOD) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return ans;
}

void solve() {
    int a, p; cin >> a >> p;
    if (a & 1) { cout << 1 << '\n'; return; }

    int ans = 0;
    for (int x = 1; x < p; x++) ans += (power(a, x, 1 << p) == power(x, a, 1 << p) ? 1 : 0);
    int k = (p + a - a) / a;
    ans += (1 << (p - k)) - (p - 1) / (1 << k);
    cout << ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}