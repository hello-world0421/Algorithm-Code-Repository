#include <bits/stdc++.h>

using namespace std;

// 定义常量，最大数据量
const int MAXN = 2 * 1e5 + 5;
// 拓扑排序，要用到队列
int q[MAXN], l, r;
// 拓扑排序，入度表
int indegree[MAXN];
// 收集拓扑排序的结果
int ans[MAXN];
int n, m;

bool topoSort(vector<vector<int>> graph)
{
    // 使用队列添加入度为 0 的点
    l = r = 0;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q[r++] = i;
    int fill = 0;
    while (l < r)
    {
        int cur = q[l++];
        ans[fill++] = cur;
        for (int next : graph[cur])
            // 删除入度为 0 的点的影响后如果入度为 0 , 则加入队列
            if (--indegree[next] == 0)
                q[r++] = next;
    }
    return fill == n;
}

int main()
{
    // 加速读入与输出
    cin.tie(nullptr)->sync_with_stdio(0), cout.tie(nullptr);
    // 点的个数与边的个数
    cin >> n >> m;
    // 动态建图
    vector<vector<int>> graph(n + 1);
    for (int i = 0, from, to; i < m; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        indegree[to]++;
    }
    if (!topoSort(graph))
        cout << -1;
    else
    {
        for (int i = 0; i < n - 1; i++)
            cout << ans[i] << ' ';
        cout << ans[n - 1] << '\n';
    }

        return 0;
}