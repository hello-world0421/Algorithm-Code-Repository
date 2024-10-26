#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> fac, inv;

ll quickPower(ll a, ll b, ll p) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void init(ll p) {
    fac.clear();
    fac.push_back(1);
    for (int i = 1; i < p; i++) {
        fac.push_back(fac.back() * i % p);
    }
    inv.resize(fac.size());
    inv[p - 1] = quickPower(fac[p - 1], p - 2, p);
    for (ll i = p - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}

ll C(ll n, ll m, ll p) {
    if (m > n || m < 0 || n < 0)
        return 0;
    return fac[n] * inv[m] % p * inv[n - m] % p;
}

ll Lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}

int main() {
    init(19);
    cout << C(16, 12, 19) << '\n';
    cout << Lucas(16, 12, 19) << '\n';

    return 0;
}