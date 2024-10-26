#include <bits/stdc++.h>
using namespace std;
constexpr int MAXM = 1e9 + 1;
constexpr int MAXN = 2e5 + 1;
int left1, left2, right1, right2;

void solve() {
    int n, s, m; cin >> n >> s >> m;
    int left1 = -1, right1 = -1, right2 = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> left1 >> right1;
        if (left1 - right2 >= s) {
            ok = true;
        }
        right2 = right1;
    }
    if (m - right2 >= s || ok) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}