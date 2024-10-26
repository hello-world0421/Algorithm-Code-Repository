/*
时间复杂度：n^2 * logn
对于题目给出的 MAXN 会 T
*/
#include <bits/stdc++.h>

using namespace std;
const int INF = 2147483647;
const int MAXN = 5 * 1e4 + 5;
const int LOGN = ceil(log2(MAXN)) + 2;

vector<int> adj[MAXN];
int dep[MAXN], fa[MAXN][LOGN], sub_size[MAXN];

void dfs(int p, int fath)
{
    sub_size[p] = 1;
    dep[p] = dep[fath] + 1;
    fa[p][0] = fath;
    for (int i = 1; (1 << i) <= dep[p]; i++)
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    for (int s : adj[p])
        if (s != fath)
        {
            dfs(s, p);
            sub_size[p] += sub_size[s];
        }
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
    for (int _ = 1; _ <= n; _++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    int ans = INF, ans_index = 0;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
            res += dep[i] + dep[j] - 2 * dep[lca(i, j)];
        if (ans > res)
        {
            ans = res;
            ans_index = i;
        }
    }
    cout << ans_index << ' ' << ans;
}