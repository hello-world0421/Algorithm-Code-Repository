#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], cnt, siz[N];
// 链式前向星建图
int idx = 1, nxt[N * 2], dian[N * 2], h[N];
ll quan[N * 2];
int n, a[N], din[N];
vector<int> e[N];
vector<int> en;
queue<int> q;
ll d[N];

// 链式前向星加边函数
void add(int a, int b)
{
    dian[++idx] = b;
    nxt[idx] = h[a];
    h[a] = idx;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++tot;
    stk[++top] = x;
    instk[x] = 1;
    for (int i = h[x]; i; i = nxt[i])
    {
        int y = dian[i];
        if (dfn[y] == 0)
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (instk[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x])
    {
        int y;
        cnt++;
        do
        {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
            siz[cnt]++;
        } while (x != y);
    }
}

void topo_sort()
{
    for (int i = 0; i <= cnt; i++)
        if (din[i] == 0)
        {
            d[i] = 0;
            q.push(i);
        }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : e[u])
            if (--din[v] == 0)
                q.push(v);
        en.push_back(u);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, a[i]);
    }
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            tarjan(i);
    for (int i = 1; i <= n; i++)
        for (int j = h[i]; j; j = nxt[j])
        {
            int y = dian[j];
            if (scc[i] != scc[y])
            {
                e[scc[i]].push_back(scc[y]);
                din[scc[y]]++;
            }
        }
    for (int i = 1; i <= cnt; i++)
    {
        e[0].push_back(i);
        din[i]++;
    }
    topo_sort();
    for (auto u : en)
        for (auto v : e[u])
        {
            ll w = siz[v];
            if (d[v] < d[u] + w)
                d[v] = d[u] + w;
        }
    ll mx = 0;
    for (int i = 1; i <= cnt; i++)
        mx = max(mx, d[i]);
    cout << mx << "\n";
    return 0;
}