#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    ll l, r, ans, mid1, mid2;
    l = 0, r = n, ans = LLONG_MAX;
    while (l <= r) {
        mid1 = (l + r) / 3;
        mid2 = mid1 * 2;
        
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}