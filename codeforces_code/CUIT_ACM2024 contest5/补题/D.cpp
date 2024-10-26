#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    ll aim = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        aim += a[i];
    }
    aim /= n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] > aim ? a[i] - aim : 0);
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