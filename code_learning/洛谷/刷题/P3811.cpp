#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 3e6 + 1;

int d, x, y, tx, ty;

ll fac[MAXN], inv[MAXN];

void exgcd(int a, int b) {
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

void init(int n, int p) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % p;
    }

    exgcd(fac[n], p); inv[n] = (x % p + p) % p;
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}

void solve() {
    int n, p; cin >> n >> p;
    init(n, p);
    for (int i = 1; i <= n; i++) {
        cout << inv[i] * fac[i - 1] % p << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}