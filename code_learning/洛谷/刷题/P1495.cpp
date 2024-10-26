#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 11;

ll m[MAXN], r[MAXN];

ll d, x, y, tx, ty;

ll bitMultiply(ll a, ll b, ll mod) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    ll ans = 0;
    while (b != 0) {
        if (b & 1) {
            ans = (ans + a) % mod;
        }
        a = (a + a) % mod; b >>= 1;
    }
    return ans;
}

void exgcd(ll a, ll b) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b);
        tx = x; ty = y;
        x = ty;
        y = tx - ty * (a / b);
    }
}

ll crt(int n) {
    ll lcm = 1;
    for (int i = 0; i < n; i++) {
        lcm *= m[i];
    }
    ll ai, ci, ans = 0;
    for (int i = 0; i < n; i++) {
        ai = lcm / m[i];
        exgcd(ai, m[i]);
        ci = bitMultiply(r[i], bitMultiply(ai, x, lcm), lcm);
        ans = (ans + ci) % lcm;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i] >> r[i];
    }
    cout << crt(n) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}