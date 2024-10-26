#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int father[MAXN], siz[MAXN], stac[MAXN];
int n;

void Build()
{
    for (int i = 0; i <= n; i++)
    {
        father[i] = i;
        siz[i] = 1;
    }
}

int Find(int i)
{
    int siz = 0;
    while (i != father[i])
    {
        stac[siz++] = i;
        i = father[i];
    }
    while (siz > 0)
        father[stac[--siz]] = i;
    return i;
}

bool isSameSet(int x, int y)
{
    return Find(x) == Find(y);
}

void Union(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy)
    {
        if (siz[fx] >= siz[fy])
        {
            siz[fx] += siz[fy];
            father[fy] = fx;
        }
        else
        {
            siz[fy] += siz[fx];
            father[fx] = fy;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int m;
    int op, x, y;
    cin >> n >> m;
    Build();
    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 1)
            cout << (isSameSet(x, y) ? "Yes" : "No") << '\n';
        else
            Union(x, y);
    }
    return 0;
}