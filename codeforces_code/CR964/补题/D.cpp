/*
双指针
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    int a = 0, b = 0;
    bool ok = false;
    while (a < s.size()) {
        if (s[a] == '?' || s[a] == t[b]) {
            s[a] = t[b++];
        }
        a++;
        if (b == t.size()) {
            ok = true;
            break;
        }
    }
    while (a < s.size()) {
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
    while (tt--) {
        solve();
    }

    return 0;
}