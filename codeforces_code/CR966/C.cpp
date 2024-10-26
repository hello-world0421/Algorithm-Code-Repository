#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int t; cin >> t;

    map<int, char> ch;
    map<char, int> num;
    while (t--) {
        ch.clear(), num.clear();
        string s; cin >> s;
        bool ok = true;
        if (a.size() != s.size()) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < s.size(); i++) {
            if (!ch.count(a[i]) && !num.count(s[i])) {
                ch[a[i]] = s[i];
                num[s[i]] = a[i];
            } else if (ch[a[i]] != s[i] || num[s[i]] != a[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}