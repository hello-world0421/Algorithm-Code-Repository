/*
组合数学 + 快速幂 + 逆元 (绑定关系，因为对于组合数的求解需要用到快速幂与逆元)
时间复杂度 预处理 + O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1001;
constexpr int MAXM = 2001;
constexpr int MOD = 998244353;

ll inv[MAXM], fac[MAXM];

// 快速幂
ll quickPow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

void init() {
    // 求阶乘
    fac[0] = 1;
    for (int i = 1; i < MAXM; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    // 求逆元
    inv[MAXM - 1] = quickPow(fac[MAXM - 1], MOD - 2);
    for (int i = MAXM - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

// 组合数 : 表示在 n 个物品中选 m 个
ll C(int n, int m) {
    if (m > n) {
        return 0;
    } else if (m == 0) {
        return 1;
    } else {
        return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    }
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    // 插板法
    // 每个位置至少放一个，求有多少种方法
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        m -= a - 1;
    }
    // 分两种情况
    // 1) 有空闲的人
    // 2) 没有空闲的人
    cout << (C(m - 1, n) + C(m - 1, n - 1)) % MOD;
}