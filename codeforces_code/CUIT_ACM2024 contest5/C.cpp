#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 101;
constexpr int MAXM = 1e9 + 1;
int l[MAXN], r[MAXN];
map<int, bool> vis, y;
int n;

bool match(int num) {
    for (int i = l[num]; i <= r[num]; i++) if (!vis.count(i)) {
        vis[i] = true;
        if (!y.count(i) || match(y[i])) {
            y[i] = num;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    y.clear();
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        vis.clear();
        if (match(i)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}