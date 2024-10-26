#include <bits/stdc++.h>

using namespace std;
const int INF = 2147483647;
const int MAXN = 1e5 + 5;
const int LOGN = ceil(log2(MAXN)) + 2;

vector<int> adj[MAXN];
int dep[MAXN], fa[MAXN][LOGN];

void dfs(int p, int fath)
{
    dep[p] = dep[fath] + 1;
    fa[p][0] = fath;
    for (int i = 1; (1 << i) <= dep[p]; i++)
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    for (int s : adj[p])
        if (s != fath)
            dfs(s, p);
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
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << dep[a] + dep[b] - 2 * dep[lca(a, b)] << '\n';
    }
}