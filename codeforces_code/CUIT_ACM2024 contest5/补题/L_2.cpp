#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 101;
constexpr int MOD = 998244353;
ll dp[MAXN][MAXN];
ll fac[MAXN], inv[MAXN];

ll quickPower(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    inv[MAXN - 1] = quickPower(fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

// 线性求解组合数
// 适用于 maxn 较大时
ll C(int n, int m) {
    if (n < 0 || m > n) {
        return 0;
    }
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void solve() {
    int n, k, m; cin >> n >> k >> m;
    string s1, s2; cin >> s1 >> s2;
    int cnt = 0;
    for (int i = 0; i < n; i++) if (s1[i] != s2[i]) {
        cnt++;
    }

    for (int i = 0; i <= k; i++) for (int j = 0; j <= n; j++) dp[i][j] = 0;
    dp[0][cnt] = 1;
    for (int i = 1; i <= k; i++) for (int j = 0; j <= n; j++) for (int x = 0; x <= j && x <= m; x++) {
        if (n - j < m - x) continue;
        dp[i][j - x + m - x] = (dp[i][j - x + m - x] + ((dp[i - 1][j] * C(j, x) % MOD) * C(n - j, m - x) % MOD)) % MOD;
    }

    cout << dp[k][0] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    init();

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}