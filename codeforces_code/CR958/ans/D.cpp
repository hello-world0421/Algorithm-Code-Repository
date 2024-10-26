#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 3 * 1e5 + 5;
// 树的大小
int n;
// 数组 a 表示节点 i 处的怪物的攻击力
// 数组 f 表示节点 i 处的第 j 回合的累计伤害
ll a[MAXN], f[MAXN][24], smn[30];
// 数组 g 表示邻接表
vector<int> g[MAXN];
void dfs(int x, int fa)
{
    // 计算节点 i 处的怪物第 j 回合的总输出
    for (int i = 1; i <= 22; i++)
        f[x][i] = i * a[x];
    // dfs 的主要过程
    for (int y : g[x])
    {
        if (y == fa)
            continue;
        dfs(y, x);
        // 动态规划的内容，看不懂
        ll tt = 8e18;
        smn[23] = 8e18;
        for (int i = 22; i >= 1; i--)
            smn[i] = min(smn[i + 1], f[y][i]);
        
        for (int i = 1; i <= 22; i++)
        {
            f[x][i] += min(tt, smn[i + 1]);
            tt = min(tt, f[y][i]);
        }
    }
}

void Solve()
{
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 建图
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    // 深度优先搜索
    dfs(1, 0);
    // 求出最小值
    cout << *min_element(f[1] + 1, f[1] + 23) << '\n';
    // 清空脏数据
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        memset(f[i], 0, sizeof(f[i]));
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        Solve();
}