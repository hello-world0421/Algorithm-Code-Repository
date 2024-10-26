#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = (i == 0 ? a[i] : a[i] + pre[i - 1]);
    }
    string s; cin >> s;
    int i = 0, j = n - 1;
    ll ans = 0;
    while (i <= j) {
        if (s[i] != 'L') {
            i++;
            continue;
        }
        if (s[j] != 'R') {
            j--;
            continue;
        }
        ans += pre[j] - (i == 0 ? 0 : pre[i - 1]);
        i++, j--;
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