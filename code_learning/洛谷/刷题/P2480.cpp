#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int fac[4][35618], inv[4][35618];
constexpr int MOD = 999'911'659;
constexpr int mod = 999'911'658;
int result[4] = { 2, 3, 4679, 35617 };

// 快速幂，用于求逆元和最后的结果
ll quickPower(ll a, ll b, ll p) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p, b >>= 1;
    }
    return ans;
}

// 初始化阶乘和逆元
void init() {
    for (int i = 0; i < 4; i++) {
        fac[i][0]= 1;
        for (ll j = 1; j < result[i]; j++) {
            fac[i][j] = fac[i][j - 1] * j % result[i];
        }

        inv[i][result[i] - 1] = quickPower(fac[i][result[i] - 1], result[i] - 2, result[i]);
        for (ll j = result[i] - 2; j >= 0; j--) {
            inv[i][j] = inv[i][j + 1] * (j + 1) % result[i];
        }
    }
}

// 计算组合数
ll C(ll n, ll m, int i) {
    if (m > n || m < 0 || n < 0)
        return 0;
    if (m > n / 2)
        m = n - m;
    return fac[i][n] * inv[i][m] % result[i] * inv[i][n - m] % result[i];
}

// 计算一个组合数对于比较小的质数取模后的结果
ll Lucas(ll n, ll m, int i) {
    if (m == 0) return 1;
    return (C(n % result[i], m % result[i], i) * Lucas(n / result[i], m / result[i], i)) % result[i];
}

ll CRT(ll* a) {
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        ll m = mod / result[i], mt = quickPower(m, result[i] - 2, result[i]);
        ans = (ans + a[i] * m % mod * mt % mod) % mod;
    }
    return (ans % mod + mod) % mod;
}

void solve() {
    int n, g; cin >> n >> g;
    if (g == MOD) {
        cout << "0\n";
        return;
    }
    ll a[4] = { 0 };
    init();
    for (ll k = 1; k <= n; k++) if (n % k == 0) {
        for (ll i = 0; i < 4; i++) {
            a[i] += Lucas(n, k, i);
        }
    }
    cout << quickPower(g, CRT(a), MOD) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}