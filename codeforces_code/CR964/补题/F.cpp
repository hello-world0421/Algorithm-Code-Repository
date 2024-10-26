/*
组合数学 ( 预处理 + 逆元 + 快速幂 )
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5 + 1, MOD = 1e9 + 7;
ll fac[MAXN], inv[MAXN];
int n, k;

ll quickPow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void init() {
    fac[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[MAXN - 1] = quickPow(fac[MAXN - 1], MOD - 2);
    for (ll i = MAXN - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll n, ll m) {
    if (m > n || m < 0 || n < 0) {
        return 0;
    } else if (m == 0) {
        return 1;
    } else {
        return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    }
}

void solve() {
    cin >> n >> k;
    int x, cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x; cnt += x;
    }
    ll ans = 0;
    for (ll i = k / 2 + 1; i <= min(cnt, k); i++) {
        ans = (ans + C(cnt, i) * C(n - cnt, k - i) % MOD) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    init();
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}