#include <bits/stdc++.h>
using namespace std;

int bigModSml(string m, int n) {
    int ans = 0;
    for (int i = 0; i < m.length(); i++) {
        ans = (ans * 10 + m[i] - '0') % n;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    string m; cin >> m;
    int ans = bigModSml(m, n);
    cout << (ans == 0 ? n : ans) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}