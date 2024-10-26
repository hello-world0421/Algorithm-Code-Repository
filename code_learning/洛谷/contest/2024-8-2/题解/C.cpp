/*
单调栈 + 数学 + 快速幂 + 逆元
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

// 快速幂
ll qpow(ll b, ll k) {
    ll res = 1;
    while (k > 0) {
        if (k & 1)
            res = res * b % mod;
        b = b * b % mod;
        k >>= 1;
    }
    return res;
}

// 求逆元（除数取模）
ll inv(ll k) {
    return qpow(k, mod - 2);
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    // 读入数据的同时计算平均值
    ll avr = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], avr += a[i];
    avr = (avr % mod * inv(n)) % mod;
    // 单调栈
    stack<array<ll, 2>> stk;
    for (int i = 1; i <= n; i++) {
        ll sum = a[i], len = 1;
        while (stk.size() && sum * stk.top()[1] <= stk.top()[0] * len) {
            sum += stk.top()[0], len += stk.top()[1], stk.pop();
        }
        stk.push({ sum, len });
    }

    // 计算方差
    ll ans = 0;
    while (stk.size()) {
        auto [sum, len] = stk.top(); stk.pop();
        ll k = sum / len, rem = sum % len;
        for (int i = 1; i <= rem; i++)
            ans = (ans + (avr - (k + 1)) * (avr - (k + 1)) % mod) % mod;
        for (int i = rem + 1; i <= len; i++)
            ans = (ans + (avr - k) * (avr - k) % mod) % mod;
    }
    ans = ans * inv(n) % mod;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}