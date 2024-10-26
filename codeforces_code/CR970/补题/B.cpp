#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1') {
            cnt++;
        } else {
            cnt--; break;
        }
    bool ok = false;
    if (cnt == n) {
        ok = (n == 4 ? true : false);
    } else {
        ok = (cnt * cnt == n ? true : false);
    }
    cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}