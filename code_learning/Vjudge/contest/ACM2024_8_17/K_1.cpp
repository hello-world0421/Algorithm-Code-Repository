#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll a, ll b, ll c) {
    ll d[3] = { a, b, c };
    sort(d, d + 3);
    for (int i = 0; i < 2; i++) {
        if (d[i] == d[i + 1]) {
            if (d[0] != 1)cout << "Win" << endl;
            else cout << "Lose" << endl;
            return;
        }
    }
    int num = 0;
    while (d[0] + d[1] + d[2] > 5) {
        ll sum = d[0] + d[1] + d[2];
        if (sum <= 5)break;
        if (d[0] == 1)break;
        d[2] = d[1] - d[0] + 1;
        num++;
        sort(d, d + 3);
    }
    if (num % 2 != 0)cout << "Win" << endl;
    else cout << "Lose" << endl;

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        ll a, b, c; cin >> a >> b >> c;
        solve(a, b, c);
    }

    return 0;
}