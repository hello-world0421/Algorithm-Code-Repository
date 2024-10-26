#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e5 + 1;
constexpr int MAXQ = 1e5 + 1;

// 储存原始数据
int n, m, q, qry[MAXQ][2];
ll V;
// 储存结果
bool ans[MAXQ];

// 邻接表形式建图
vector<pair<int, ll>> adj[MAXN];
// ？
int bel[MAXN];

// 求包含 S 的连通块，要求所选边权 t 里所有的 1
void bfs(int S, ll t) {
    queue<int> q;
    q.push(S); bel[S] = S;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = 0; i < adj[sn].size(); i++) {
            int fn = adj[sn][i].first;
            ll val = adj[sn][i].second;
            if (bel[fn] || (val & t) != t) continue;
            q.push(fn); bel[fn] = S;
        }
    }
}

// 对于前缀 t 检查哪些点是连通的
void gao(ll t) {
    memset(bel, 0, sizeof(int) * (n + 3));
    // 通过 bfs 检查两个点是否位于同一连通块
    for (int i = 1; i <= n; i++) if (!bel[i]) bfs(i, t);
    for (int i = 1; i <= q; i++) ans[i] = ans[i] || bel[qry[i][0]] == bel[qry[i][1]];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> q >> V;
    for (int i = 1; i <= n; i++) {
        int x, y; ll z; cin >> x >> y >> z;
        adj[x].push_back({ y, z });
        adj[y].push_back({ x, z });
    }
    for (int i = 1; i <= q; i++) cin >> qry[i][0] >> qry[i][1];

    if (V == 0) gao(0);
    else for (ll t = V; t < (1ll << 60); t += t & (-t)) gao(t);

    for (int i = 1; i <= q; i++)
        cout << (ans[i] ? "Yes\n" : "No\n");

    return 0;
}