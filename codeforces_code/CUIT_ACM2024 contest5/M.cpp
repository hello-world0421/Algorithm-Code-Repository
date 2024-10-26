#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string week[5] = { "Monday", "Tuesday", "Wednesday", "Thursday" , "Friday" };

void solve() {
    ll y1, m1, d1; cin >> y1 >> m1 >> d1;
    string s; cin >> s;
    int tim = 0;
    for (int i = 0; i < 5; i++) {
        if (week[i] == s) {
            tim = i;
            break;
        }
    }
    ll y2, m2, d2; cin >> y2 >> m2 >> d2;
    ll ans = ((d2 - d1) % 5 + 5) % 5;
    cout << week[(tim + ans) % 5] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}