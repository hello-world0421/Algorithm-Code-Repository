#include <bits/stdc++.h>
using namespace std;

public:
static const int MAXN = 35;

int father[MAXN];

int sets;

int n;

void Build(int m)
{
    for (int i = 0; i <= m; i++)
        father[i] = i;
    sets = m;
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
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy)
    {
        father[fx] = fy;
        sets--;
    }
}

int minSwapsCouples(vector<int> &row)
{
    n = row.size();
    Build(n / 2);
    for (int i = 0; i < n; i += 2)
        Union(row[i] / 2, row[i + 1] / 2);
    return n / 2 - sets;
}