#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int w; cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](int a, int b) {
        return a > b;
    });
    map<ll, ll> mp;
    for (ll i = 1; i <= k; i++) {
        for (ll j = 1; j <= k; j++) {
            if (i < k && j < k) {
                mp[i * j] += 4;
            } else if (i != j && (i == k || j == k)) {
                mp[i * j] += 2;
            } else {
                mp[i * j] += 1;
            }
        }
    }
    ll ans = 0, mi = k, mj = k;
    for (auto i : a) {
        if (mp[mi * mj] > 0) {
            cout << i * mi * mj << ' ';
            ans += i * mi * mj;
            mp[mi * mj]--;
        } else {
            mi >= mj ? mi-- : mj--;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}