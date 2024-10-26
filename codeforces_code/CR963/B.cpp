#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b;
    ll even = 0, qi = 0, maxqi = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            qi++, maxqi = max(maxqi, a[i]);
        } else {
            b.push_back(a[i]);
            even++;
        }
    }
    if (qi == 0 || even == 0) {
        cout << '0' << '\n';
        return;
    }
    ll ans = 0;
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++) {
        while (b[i] > maxqi) {
            ans++; maxqi += b[b.size() - 1];
        }
        ans++; maxqi += b[i];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}