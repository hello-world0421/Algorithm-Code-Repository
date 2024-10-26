#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define lowbit(x) (x & (-x))
using namespace std;
using ll = long long;
const int N = 2e5 + 7;
const int mod = 998244353;
vector<int> G[N];
int a[N];
int tr[N];
int dp[N][26];
int l[N], r[N];
int s[N];
int p[N][22];
int dep[N];
int tot;
string str[N];
struct Bit
{
    int n;
    void add(int now, int val)
    {
        for (int i = now; i <= n; i += lowbit(i))
            tr[i] += val;
    }
    int query(int now)
    {
        int ans = 0;
        for (int i = now; i; i -= lowbit(i))
            ans += tr[i];
        return ans;
    }
} T;
void dfs(int now, int fa)
{
    if (p != 0)
        s[now] = (a[now] - a[fa] + 26) % 26;
    dep[now] = dep[fa] + 1;
    l[now] = ++tot;
    p[now][0] = fa;
    for (int i = 1; i < 22; i++)
        p[now][i] = p[p[now][i - 1]][i - 1];
    for (auto it : G[now])
    {
        if (it == fa)
            continue;
        dfs(it, now);
    }
    r[now] = tot;
}
int LCA(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 21; i >= 0; i--)
        if (dep[p[x][i]] >= dep[y])
            x = p[x][i];
    if (x == y)
        return x;
    for (int i = 21; i >= 0; i--)
        if (p[x][i] != p[y][i])
            x = p[x][i], y = p[y][i];
    return p[x][0];
}
void calc(int x, int f)
{
    bool ok = 0;
    for (int i = 0; i < 26; i++)
        ok |= (dp[x][i] >= 2);
    T.add(l[x], ok * f);
    T.add(r[x] + 1, -ok * f);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> str[i], a[i] = str[i][0] - 'a';
    for (int i = 1; i <= n; i++)
        for (auto it : G[i])
            dp[i][(a[i] - a[it] + 26) % 26]++;
    dfs(1, 0);
    T.n = n;
    for (int i = 1; i <= n; i++)
        calc(i, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            if (x != 1)
            {
                calc(x, -1);
                calc(p[x][0], -1);
                dp[x][s[x]]--;
                dp[p[x][0]][(26 - s[x]) % 26]--;
                s[x]++;
                s[x] %= 26;
                dp[x][s[x]]++;
                dp[p[x][0]][(26 - s[x]) % 26]++;
                calc(x, 1);
                calc(p[x][0], 1);
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            int z = LCA(x, y);
            int ans = T.query(l[x]) + T.query(l[y]) - T.query(l[z]) - T.query(l[p[z][0]]);
            cout << ans << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}