#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5 + 1;
int a[MAXN], b[MAXN], mp[MAXN];

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
        a[i] = 0; b[i] = 0; mp[i] = 0;
    }
    ll cnt = 0;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        mp[x]++;
        if (mp[x] == 2) cnt++;
        if (y == 0) { a[x]++; } else { b[x]++; };
    }
    ll ans = cnt * (n - 2);
    for (int i = 1; i < n; i++) {
        if (a[i] == 1 && b[i - 1] == 1 && b[i + 1] == 1) ans++;
        if (b[i] == 1 && a[i - 1] == 1 && a[i + 1] == 1) ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}