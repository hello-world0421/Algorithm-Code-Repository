/*
模拟
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int a = 0, b = 0, n = s.size();
    for (int i = 0; i + 1 < n; i += 2) {
        a = a * 10 + (s[i] - '0');
        b = b * 10 + (s[i + 1] - '0');
    }
    if (n & 1) a = a * 10 + (s[n - 1] - '0');
    cout << (a + 1) * (b + 1) - 2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}