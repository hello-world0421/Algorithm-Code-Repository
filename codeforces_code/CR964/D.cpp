#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 1;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int a = 0, b = 0;
    bool ok = false;
    while (a < n) {
        if (s[a] == t[b] || s[a] == '?') {
            s[a] = t[b++];
        }
        a++;
        if (b == m) {
            ok = true;
            break;
        }
    }
    while (a < n) {
        if (s[a] == '?') {
            s[a] = 'a';
        }
        a++;
    }
    if (ok) {
        cout << "YES\n" << s << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}