#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll manhaton(ll x, ll y) {
    return abs(x) + abs(y);
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    ll x = 0, y = 0;
    ll ans = -1;
    for (auto ch : s) {
        if (ch == 'U') {
            y++;
        } else if (ch == 'D') {
            y--;
        } else if (ch == 'R') {
            x++;
        } else if (ch == 'L') {
            x--;
        }
        ans = max(ans, manhaton(x, y));
    }
    x = (k - 1) * x, y = (k - 1) * y;
    for (auto ch : s) {
        if (ch == 'U') {
            y++;
        } else if (ch == 'D') {
            y--;
        } else if (ch == 'R') {
            x++;
        } else if (ch == 'L') {
            x--;
        }
        ans = max(ans, manhaton(x, y));
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