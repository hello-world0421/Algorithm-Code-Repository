#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5 * 1e5 + 5;
const int LOGN = 30;

vector<int> adj[MAXN];
int dep[MAXN];
int fa[MAXN][LOGN];

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
    for (int i = 28; i >= 0; i--)
        if (dep[a] - (1 << i) >= dep[b])
            a = fa[a][i];
    if (a == b)
        return a;

    for (int i = 28; i >= 0; i--)
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    return fa[a][0];
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(s, 0);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}
