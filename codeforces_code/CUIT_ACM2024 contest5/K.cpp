#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll quickPower(int a, int b, int p) {
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

ll exGcd(int a, int b, int& x, int& y) {
    
}

void solve() {
    int a, p; cin >> a >> p;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}