#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 5e4 + 5;
int father[MAXN], stac[MAXN], siz = 0;
unordered_map<string, int> mp1;
unordered_map<int, string> mp2;
string fath, son, temp;

void initialize()
{
    for (int i = 1; i <= MAXN - 4; i++)
        father[i] = i;
}

int find_root(int i)
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
    return find_root(x) == find_root(y);
}

void merge_sets(int x, int y)
{
    father[find_root(x)] = find_root(y);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> temp;
    initialize();
    while (temp.compare("$"))
    {
        if (temp[0] == '#')
        {
            fath = temp.substr(1, temp.size() - 1);
            mp1.emplace(fath, ++siz);
            mp2.emplace(siz, fath);
        }
        else if (temp[0] == '+')
        {
            son = temp.substr(1, temp.size() - 1);
            mp1.emplace(son, ++siz);
            mp2.emplace(siz, son);
            merge_sets(mp1[son], mp1[fath]);
        }
        else if (temp[0] == '?')
        {
            son = temp.substr(1, temp.size() - 1);
            cout << son << ' ' << mp2[find_root(mp1[son])] << '\n';
        }
        cin >> temp;
    }
    return 0;
}