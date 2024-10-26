#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    bool ok[n + 1];
    vector<pair<int, int>> p;
    int low[n + 1], high[n + 1];
    bitset<101> mp, ans;

    fill(ok + 1, ok + n + 1, true);
    fill(low, low + n + 1, 0);
    fill(high, high + n + 1, 0);
    bool flag = true;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (!mp.test(a)) mp.set(a);
        if (!mp.test(b)) mp.set(b);
        if (a == b) {
            flag = false;
            continue;
        }
        low[a]++, high[b]++;
        p.push_back({ a, b });
    }
    if (!flag) {
        for (int i = 0; i < n; i++)
            cout << '0';
        cout << '\n'; return;
    }
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}