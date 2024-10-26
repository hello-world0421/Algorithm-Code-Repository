#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    ll tot = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    if (tot % n != 0) {
        ans += tot % n;
        tot -= tot % n;
    }
    ll aim = tot / n;
    for (int i = 0; i < n; i++)
        if (a[i] < aim)
            ans += aim - a[i];
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}