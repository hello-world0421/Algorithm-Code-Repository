#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5 * 1e4 + 5;
const int INF = 999999;
const int LOGN = ceil(log2(MAXN)) + 5;

vector<int> adj[MAXN];
int sz[MAXN], mss[MAXN], n, ctr = INF;
int dep[MAXN], fa[MAXN][LOGN];

void dfs(int p, int fath = 0)
{
    sz[p] = 1;
    mss[p] = 0;
    dep[p] = dep[fath] + 1;
    fa[p][0] = fath;
    for (int i = 1; (1 << i) <= dep[p]; i++)
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    for (auto s : adj[p])
        if (s != fath)
        {
            dfs(s, p);
            mss[p] = max(mss[p], sz[s]);
            sz[p] += sz[s];
        }
    mss[p] = max(mss[p], n - sz[p]);
    if (mss[p] <= n / 2 && p < ctr)
        ctr = p;
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = LOGN - 1; i >= 0; i--)
        if (dep[a] - (1 << i) >= dep[b])
            a = fa[a][i];
    if (a == b)
        return a;

    for (int i = LOGN - 1; i >= 0; i--)
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int ans = 0, root = ctr;
    for (int i = 1; i <= n; i++)
        ans += dep[i] + dep[root] - 2 * dep[lca(i, root)];
    cout << root << ' ' << ans;

    return 0;
}