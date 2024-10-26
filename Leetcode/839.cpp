#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 305;

int father[MAXN];

int sets;

void Build(int n)
{
    for (int i = 0; i < n; i++)
        father[i] = i;
    sets = n;
}

int Find(int i)
{
    if (i != father[i])
        father[i] = Find(father[i]);
    return father[i];
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

int numSimilarGroups(vector<string> &strs)
{
    int n = strs.size();
    int m = strs[0].size();
    Build(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (Find(i) != Find(j))
            {
                int diff = 0;
                for (int k = 0; k < m && diff < 3; k++)
                    if (strs[i].at(k) != strs[j].at(k))
                        diff++;
                if (diff == 0 || diff == 2)
                    Union(i, j);
            }
    return sets;
}