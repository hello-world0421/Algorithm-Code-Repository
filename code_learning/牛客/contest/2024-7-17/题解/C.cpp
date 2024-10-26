#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// 关键变量
const int N = 5005;
int n, k, a, ans;
bool vis[N];  // 标记变量（每次匹配会重置）
int match[N];  // 已匹配变量
// 使用邻接表的二分图匹配
vector<int> e[N];
// match 函数
bool dfs(int u)
{
    for (int v : e[u])
    {
        if (vis[v])
            continue;
        vis[v] = 1;
        if (match[v] == 0 || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    // 读入并存取数据
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a;
            e[i].push_back(a);
        }
    }
    // 处理过程
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ans++;
    }
    // 输出答案
    if (ans == n)
        cout << "Yes\n";
    else
    {
        cout << "No\n";
        cout << n - ans << "\n";
    }
    return 0;
}