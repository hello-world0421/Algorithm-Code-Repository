#include <bits/stdc++.h>

using namespace std;
#define INF 2147483647

const int MAXN = 100 + 5;
const int LOGN = ceil(log2(MAXN));

pair<int, int> adj[MAXN];
int dep[MAXN], pw[MAXN];
int fa[MAXN][LOGN + 2];

void dfs(int p, int fath)
{
    if (p == 0)
        return;
    dep[p] = dep[fath] + 1;
    fa[p][0] = fath;
    for (int i = 1; (1 << i) <= dep[p]; i++)
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    dfs(adj[p].first, p);
    dfs(adj[p].second, p);
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = LOGN; i >= 0; i--)
        if ((dep[a] - (1 << i)) >= dep[b])
            a = fa[a][i];
    if (a == b)
        return a;

    for (int i = LOGN; i >= 0; i--)
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

int main()
{
    int n, ans = INF;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int w, u, v;
        cin >> w >> u >> v;
        pw[i] = w;
        adj[i] = make_pair(u, v);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        int s = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            s += (dep[i] + dep[j] - 2 * dep[lca(i, j)]) * pw[j];
        }
        ans = min(ans, s);
    }
    cout << ans;
}