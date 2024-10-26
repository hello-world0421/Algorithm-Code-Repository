#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
// 数组 a 用于存储题目给定的数据
ll a[N];
// 数组 e 用于存储拓扑排序的结果
vector<int> e;
// 队列 q 用于拓扑排序
queue<int> q;
int n;
// 数组 din 表示每个点的入度
// 数组 son 表示每个点的儿子
int din[N], son[N], sz[N], tot[N], d[N];
int cnt = 0;
bool b[N];

void topo() // 拓扑排序
{
    for (int i = 1; i <= n; i++)
        if (din[i] == 0)
            q.push(i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        din[son[u]]--;
        if (din[son[u]] == 0)
            q.push(son[u]);
        e.push_back(u);
    }
}

int main()
{
    // 读入数据并记录每个点的入度
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        son[i] = a[i]; // 每个点只有一个出度，即只有一条出边。我们直接用son数组来存放，其实用a数组直接存放也可以。
        din[a[i]]++;   // 记录每个点的入度。
    }
    // 拓扑排序
    topo();
    cnt = n;
    for (auto u : e) // 将拓扑序列中的每个点作为一个新的集合，并求出该集合的点权值。
    {
        cnt++;
        tot[u] = cnt; // 将 u 所在的集合的编号赋值为 cnt
        sz[cnt]++;    // 更新编号为 cnt 的集合的点权值。
    }
    for (int i = 1; i <= n; i++)
        if (din[i] && b[i] == 0) // 将组成一个环的所有的点表示成一个集合，并求出该集合的点权值。
        {
            cnt++;
            b[cnt] = 1;
            int u = i;
            while (b[u] == 0)
            {
                b[u] = 1;
                sz[cnt]++;
                tot[u] = cnt;
                u = son[u];
            }
        }
    for (int i = n + 1; i <= cnt; i++)
        d[i] = sz[i]; // 每个集合的答案的初值为该集合中点的个数。
    ll mx = 0;
    for (auto u : e)
    {
        int v = son[u];
        d[tot[v]] = max(d[tot[v]], d[tot[u]] + sz[tot[v]]); // 通过拓扑序中靠前的点的答案来更新靠后的点的答案。
        mx = max(mx, (ll)d[tot[v]]);                        // 更新答案的同时更新求解最终答案。
        mx = max(mx, (ll)d[tot[u]]);
    }
    for (int i = n + 1; i <= cnt; i++) // 利用构成封闭连通块的环来更新求解最终的答案。
        if (b[i])
            mx = max(mx, (ll)d[i]);
    cout << mx << "\n";
    return 0;
}