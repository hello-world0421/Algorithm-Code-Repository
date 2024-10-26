#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5 + 1;

ll r[MAXN], m[MAXN];

ll d, x, y, tx, ty;

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

ll bitMultiply(ll a, ll b, ll mod) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    ll ans = 0;
    while (b > 0) {
        if (b & 1) {
            ans = (ans + a) % mod;
        }
        a = (a + a) % mod; b >>= 1;
    }
    return ans;
}

ll excrt(int n) {
    ll tail = 0, lcm = 1, tmp, b, c, x0;
    for (int i = 0; i < n; i++) {
        b = m[i];
        c = ((r[i] - tail) % b + b) % b;
        exgcd(lcm, b);
        if (c % d != 0) {
            return -1;
        }
        x0 = bitMultiply(x, c / d, b / d);
        tmp = lcm * (b / d);
        tail = (tail + bitMultiply(x0, lcm, tmp)) % tmp;
        lcm = tmp;
    }
    return tail;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i] >> r[i];
    }
    cout << excrt(n) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}