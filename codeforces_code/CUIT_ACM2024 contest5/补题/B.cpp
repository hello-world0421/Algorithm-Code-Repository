/*
bfs
时间复杂度 O(nm)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 101;
vector<int> adj[MAXN];
bitset<MAXN> vis;
// 利用 bfs 计算一个节点的前继节点和后继节点的数量
int pre[MAXN], suc[MAXN];
int n, m;

bool bfs(int s) {
    queue<int> q;
    vis.reset();
    q.push(s); vis.set(s);
    while (!q.empty()) {
        int fa = q.front(); q.pop();
        for (auto sn : adj[fa]) {
            if (sn == s) return false;
            if (vis.test(sn)) continue;
            vis.set(sn); q.push(sn);
            pre[sn]++, suc[s]++;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    fill(pre + 1, pre + n + 1, 0);
    fill(suc + 1, suc + n + 1, 0);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!bfs(i)) {
        for (int i = 0; i < n; i++) {
            cout << '0';
        }
        cout << '\n'; return;
    }
    for (int i = 1; i <= n; i++) {
        cout << (pre[i] <= n / 2 && suc[i] <= n / 2 ? 1 : 0);
    }
    cout << '\n'; return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}