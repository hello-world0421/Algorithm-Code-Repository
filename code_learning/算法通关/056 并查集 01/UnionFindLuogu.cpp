#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;

int father[MAXN];
int n;

void Build()
{
    for (int i = 0; i <= n; i++)
        father[i] = i;
}

int Find(int i)
{
    if (i != father[i])
        father[i] = Find(father[i]);
    return father[i];
}

bool isSameSet(int x, int y)
{
    return Find(x) == Find(y);
}

void Union(int x, int y)
{
    father[Find(x)] = Find(y);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    Build();
    int op, x, y;
    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 1)
            Union(x, y);
        else
            cout << (isSameSet(x, y) ? "Y" : "N") << '\n';
    }

    return 0;
}