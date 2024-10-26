#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 3e5 + 5;

int father[MAXN];
map<string, int> mp;

void Build(int n)
{
    for (int i = 0; i < n; i++)
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
    father[Find(x)] = Find(y);
}

int main()
{
    int x, y, g, siz = 0;
    cin >> x;
    vector<pair<string, string>> gathers;
    vector<pair<string, string>> notGathers;
    string stu1, stu2, stu3;
    if (x != 0)
    {
        gathers.resize(x);
        for (int i = 0; i < x; i++)
        {
            cin >> stu1 >> stu2;
            gathers[i] = {stu1, stu2};
        }
    }
    cin >> y;
    if (y != 0)
    {
        notGathers.resize(y);
        for (int i = 0; i < y; i++)
        {
            cin >> stu1 >> stu2;
            notGathers[i] = {stu1, stu2};
        }
    }
    cin >> g;
    Build(3 * g);
    for (int i = 1; i <= g; i++)
    {
        cin >> stu1 >> stu2 >> stu3;
        mp.emplace(stu1, ++siz);
        mp.emplace(stu2, ++siz);
        mp.emplace(stu3, ++siz);
        Union(mp.at(stu1), mp.at(stu2));
        Union(mp.at(stu1), mp.at(stu3));
    }
    int ans = 0;
    if (x != 0)
        for (auto stus : gathers)
            ans += (isSameSet(mp.at(stus.first), mp.at(stus.second)) ? 0 : 1);
    if (y != 0)
        for (auto stus : notGathers)
            ans += (isSameSet(mp.at(stus.first), mp.at(stus.second)) ? 1 : 0);
    cout << ans;
}