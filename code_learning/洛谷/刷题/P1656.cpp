// 还需要学习 tarjan算法和最大连通量算法才能做出来
#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 155;
static const int MAXM = 1e4 + 5;
int head[MAXN], nxt[MAXM], to[MAXM];
int cnt = 1;
int din[MAXN];
int n, m;

void addEdge(int u, int v)
{
    nxt[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
        din[v]++, din[u]++;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        if (din[i] == 1)
        {
            if (i <= to[head[i]])
                mp.emplace(i, to[head[i]]);
            else
                mp.emplace(to[head[i]], i);
        }
    for (auto ans : mp)
        cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}