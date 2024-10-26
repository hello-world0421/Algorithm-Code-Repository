#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

vector<int> adj[MAXN];
int dep[MAXN], max_dep;
vector<int> root;

void dfs(int p, int fath)
{
    dep[p] = dep[fath] + 1;
    max_dep = max(max_dep, dep[p]);
    for (int s : adj[p])
        if (s != fath)
            dfs(s, p);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        if (v != -1)
        {
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
        else
            root.push_back(i);
    }
    for (int i : root)
    {
        dfs(i, 0);
    }
    cout << max_dep;
}