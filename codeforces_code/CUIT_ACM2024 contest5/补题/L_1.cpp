/*
动态规划
时间复杂度 O(nmk)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 101;
constexpr int MOD = 998244353;
ll C[MAXN][MAXN], dp[MAXN][MAXN];

// maxn^2求解组合数
// 适用于 maxn 较小时
void init() {
    for (int i = 0; i < MAXN; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
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
        dp[i][j - x + m - x] = (dp[i][j - x + m - x] + ((dp[i - 1][j] * C[j][x] % MOD) * C[n - j][m - x] % MOD)) % MOD;
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