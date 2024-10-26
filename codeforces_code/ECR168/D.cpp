#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 1;
pair<int, vector<int>> adj[MAXN];

int dfs(int cur, int fath)
{
    int min_num = 0x7fffff;
    for (auto s : adj[cur].second)
        if (s != fath)
            min_num = min(min_num, dfs(s, cur));
    if (min_num != 0x7fffff)
        adj[cur].first += min_num;
    return adj[cur].first;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        adj[i] = {0, {}};
    int v;
    for (int i = 1; i <= n; i++)
        cin >> adj[i].first;
    for (int i = 2; i <= n; i++)
    {
        cin >> v;
        adj[v].second.push_back(i);
        adj[i].second.push_back(v);
    }
    cout << dfs(1, 0) << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}