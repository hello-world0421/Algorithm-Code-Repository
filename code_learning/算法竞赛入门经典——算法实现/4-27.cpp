/*
【倍增 LCA】村庄有多远：
    一个村庄有 n 栋房子和 n - 1 条双向路，每两栋房子之间都有一条唯一
路径，任意一条路径都给出一个长度。现在有 m 次询问，每个询问给出 u ，v ，
求 u ，v 之间的距离。
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5 * 1e5 + 5;
int N, L, Tin[MAXN], Tout[MAXN], UP[MAXN][18], timer;


vector<pair<int, int>> adj[MAXN];
int Dist[MAXN], dep[MAXN];

void dfs(int u, int fa) {
    Tin[u] = ++timer, UP[u][0] = fa;
    if (u)
        dep[u] = dep[fa] + 1;
    for (int i = 1; i < L; i++)
        UP[u][i] = UP[UP[u][i - 1]][i - 1];
    for (auto s : adj[u]) {
        if (s.first != fa)
            dfs(s.first, u);
    }
    Tout[u] = ++timer;
}

bool isAncestor(int u, int v) {
    return Tin[u] <= Tin[v] && Tout[u] >= Tout[v];
}

int LCA(int u, int v) {
    if (dep[u] > dep[v])
        return LCA(v, u);
    if (isAncestor(u, v))
        return u;
    for (int i = L; i >= 0; i--)
        if (!isAncestor(UP[u][i], v))
            u = UP[u][i];
    return UP[u][0];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T, M, u, v, k;
    L = ceil(log2(N));
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            adj[i].clear();
        for (int i = 0; i < N - 1; i++)
        {
            cin >> u >> v >> k, u--, k--;
            adj[u].push_back(pair(v, k)), adj[v].push_back(pair(u, k));
        }
        memset(UP, 0, sizeof(UP));
        Dist[0] = 0, dep[0] = 0;
        dfs(0, 0);
        for (int i = 0; i < M; i++) {
            cin >> u >> v, u--, v--;
            cout << Dist[u] + Dist[v] - 2 * Dist[LCA(u, v)] << '\n';
        }
    }
    return 0;
}