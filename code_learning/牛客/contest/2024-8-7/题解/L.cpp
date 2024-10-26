/*
概率dp + 逆元
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 1, MOD = 998'244'353;

ll n;
// 数组 dp 维护的是以 si 结尾的字符的概率
// 其中 0 表示相同字符串组成的概率，1 表示不严格递减字符串组成的概率，2 表示不严格递增字符串组成的概率
// 因为当计算以某个字符结尾单调的概率的时候如果其出现多次，后面的字符取与不取均为以该字符结尾的情况
ll dp[123][3], p[MAXN];
ll fact[MAXN], inv[MAXN];

// 快速幂
ll quickPow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

// 初始化
void init() {
    fact[0] = 1;
    for (int i = 1; i <= 1'000'000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    ll infact = quickPow(fact[1'000'000], MOD - 2);

    // 初始化逆元
    for (int i = 1'000'000; i >= 1; i--) {
        inv[i] = infact * fact[i - 1] % MOD;
        infact = infact * i % MOD;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    init();
    cin >> n;
    string s; cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // 空串的概率
    ll dlt = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (j < s[i])
                dp[s[i]][1] = (dp[s[i]][1] + dp[j][1] * inv[p[i]] % MOD) % MOD;
            if (j > s[i])
                dp[s[i]][2] = (dp[s[i]][2] + dp[j][2] * inv[p[i]] % MOD) % MOD;
        }

        for (int j = 'a'; j <= 'z'; j++) {
            if (j == s[i]) continue;
            for (int k = 0; k < 3; k++)
                dp[j][k] = dp[j][k] * ((1 - inv[p[i]] + MOD) % MOD) % MOD;
        }

        for (int j = 0; j < 3; j++)
            dp[s[i]][j] = (dp[s[i]][j] + dlt * inv[p[i]] % MOD) % MOD;
        dlt = dlt * ((1 - inv[p[i]] + MOD) % MOD) % MOD;
    }

    ll ans = 0;
    for (int i = 'a'; i <= 'z'; i++)
        ans = ((ans + (dp[i][1] + dp[i][2]) % MOD) % MOD - dp[i][0] + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}