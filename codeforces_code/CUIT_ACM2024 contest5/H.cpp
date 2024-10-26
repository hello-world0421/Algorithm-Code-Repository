#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll max_dis = -1;
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            x++;
        } else if (s[i] == 'L') {
            x--;
        } else if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        }
        max_dis = max(max_dis, abs(x) + abs(y));
    }
    x = (k - 1) * x, y = (k - 1) * y;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            x++;
        } else if (s[i] == 'L') {
            x--;
        } else if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        }
        max_dis = max(max_dis, abs(x) + abs(y));
    }
    cout << max_dis << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}