#include <bits/stdc++.h>
using namespace std;
int x, y, a, b;

void solve() {
    cin >> x >> y;
    vector<int> ans;
    a = x / y, b = x % y;
    while (b > 0) {
        ans.push_back(a);
        x = y; y = b;
        a = x / y, b = x % y;
    }
    ans.push_back(a);
    int n = ans.size();
    cout << n - 1 << ' ';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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