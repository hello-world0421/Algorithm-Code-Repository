#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans[10001];
void init() {
    ll x = 1, n = 1, y = 1;
    for (int i = 1; i <= 10000; i++) {
        ans[i] = ans[i - 1] + x;
        n--;
        if (n == 0) {
            n = y + 1;
            x <<= 1;
            y++;
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << ans[n] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();
    for (int i = 1; i < 1001; i++) {
        cerr << ans[i] << ' ';
    }
    cerr << '\n';
    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}