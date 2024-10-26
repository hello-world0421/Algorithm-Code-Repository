#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj;
bool vis[1001][1001];
bool ok = true;
int query(int a, int b) {
    int ans;
    cout << "? " << a << " " << b << endl;
    cin >> ans;
    return ans;
}

void f(int a, int b) {
    int ans = query(a, b);
    if (ans == -1) {
        ok = false;
        return;
    }
    vis[a][b] = true;
    vis[b][a] = true;
    if (ans == a) {
        adj.push_back({ a, b });
    } else {
        int a1 = min(ans, a), a2 = max(ans, a);
        int b1 = min(ans, b), b2 = max(ans, b);
        if (!vis[a1][a2])
            f(a1, a2);
        if (!vis[b1][b2])
            f(b1, b2);
    }
}

void solve() {
    int n; cin >> n;
    adj.clear();
    memset(vis, false, sizeof(vis));

    for (int i = 2; i <= n; i++) {
        if (!vis[1][i])
            f(1, i);
        if (!ok) {
            return;
        }
    }
    cout << "! ";
    for (int i = 0; i < adj.size(); i++) {
        cout << adj[i].first << ' ' << adj[i].second << ' ';
    }
    cout << endl;
}

int main() {
    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}