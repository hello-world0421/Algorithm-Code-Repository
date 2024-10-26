#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, t; cin >> n >> t;
    ll pow2 = 1;
    if (n == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= t && pow2 <= n; i++) {
        pow2 *= 2;
    }
    cout << (n + pow2 - 1) / pow2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}