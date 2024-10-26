#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 4e5 + 7;
const int mod = 998244353;
template <class T> // 求联通分量法
struct SCC
{
#define first fi
#define second se
    int n;
    vector<std::vector<std::pair<int, int>>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    vector<int> siz;
    vector<std::vector<int>> ans; // 存边双
    int cur, cnt;
    SCC() {}
    SCC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        adj.assign(n + 1, {});
        ans.assign(0, {});
        dfn.assign(n + 1, -1);
        low.resize(n + 1, -1);
        bel.assign(n + 1, -1);
        siz.resize(n + 1, 0);
        stk.clear();
        cur = cnt = 0;
    }
    void add(int u, int v, int id = 0) // 记得存反边的编号
    {
        adj[u].push_back({v, id << 1});
        adj[v].push_back({u, id << 1 | 1});
    }
    void tarjan(int u, int last = 0)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto [v, id] : adj[u])
        {
            if (id == (last ^ 1))
                continue;
            if (dfn[v] == -1)
            {
                tarjan(v, id);
                low[u] = min(low[u], low[v]);
            }
            else
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            ++cnt;
            int y;
            vector<int> tempans;
            do
            {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
                tempans.push_back(y);
                siz[cnt]++;
            } while (y != u);
            ans.push_back(tempans);
        }
    }
    vector<int> work(int n)
    {
        vector<int> dp(n, 0);
        for (int i = 1; i <= n; i++)
        {
            if (dfn[i] == -1)
            {
                tarjan(i, 0);
            }
        }
        vector<int> v;
        vector<int> mp(n + 1, 0);
        for (auto j : ans)
        {
            v.push_back(j.size());
            mp[j.size()]++;
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        dp[0] = 1;
        ll res = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int tot = mp[v[i]];
            for (int k = 1; k <= tot; k <<= 1)
            {
                tot -= k;
                int w = k * v[i];
                for (int j = (n + 1) / 2; j >= w; --j)
                {
                    dp[j] |= dp[j - w];
                }
            }
            if (tot)
            {
                int w = tot * v[i];
                for (int j = (n + 1) / 2; j >= w; --j)
                {
                    dp[j] |= dp[j - w];
                }
            }
        }
        for (int i = 0; i <= (n + 1) / 2; ++i)
        {
            if (dp[i])
                res = max(res, 1ll * (n - i) * i);
        }
        cout << res;
        return bel;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    SCC<int> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.add(u, v, i);
    }
    g.work(n);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}