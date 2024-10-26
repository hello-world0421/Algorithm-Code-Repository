#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 1e4 + 5;
int father[MAXN];
// { price , value }
vector<pair<int, int>> val;
int n, m, w;

void Build(int n)
{
    for (int i = 1; i <= n; i++)
        father[i] = i;
}

int Find(int i)
{
    if (father[i] != i)
        father[i] = Find(father[i]);
    return father[i];
}

bool isSameSet(int x, int y)
{
    return Find(x) == Find(y);
}

void Union(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    val[fy].first += val[fx].first;
    val[fy].second += val[fx].second;
    father[fx] = fy;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> w;
    int c, d;
    int u, v;
    Build(n);
    val.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> d;
        val[i] = {c, d};
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        Union(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (father[i] == i)
            cout << i << ':'<< val[i].first 
            << ','<< val[i].second << '\n';
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (father[i] == i && val[i].first <= w)
            ans = max(ans, val[i].second);
    cout << ans;

    return 0;
}