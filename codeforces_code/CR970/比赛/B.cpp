#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1') cnt++;
        else { cnt--; break; };
    if (n == 1 && s == "1") {
        cout << "Yes\n";
    } else if (n == 4) {
        if (cnt == 4) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if (sqrt(n) == int(sqrt(n)) && sqrt(n) == cnt) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}