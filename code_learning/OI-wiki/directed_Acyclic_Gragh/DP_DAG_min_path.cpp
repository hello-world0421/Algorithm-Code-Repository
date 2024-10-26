#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct edge
{
    int v, w;
};

int n, m;
vector<edge> e[MAXN];
vector<int> L;                               // 存储拓扑排序结果
int max_dis[MAXN], min_dis[MAXN], in[MAXN];  // in 存储每个节点的入度

void toposort()  // 拓扑排序
{
    queue<int> S;
    memset(in, 0, sizeof(in));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < e[i].size(); j++)
            in[e[i][j].v]++;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            S.push(i);
    while (!S.empty())
    {
        int u = S.front();
        S.pop();
        L.push_back(u);
        for (int i = 0; i < e[u].size(); i++)
            if (--in[e[u][i].v] == 0)
                S.push(e[u][i].v);
    }
}

void dp(int s)  // 以 s 为起点求单源最长（短）路
{
    toposort(); // 先进行拓扑排序
    memset(min_dis, 0x3f, sizeof(min_dis));
    memset(max_dis, 0, sizeof(max_dis));
    min_dis[s] = 0;
    for (int i = 0; i < L.size(); i++)
    {
        int u = L[i];
        for (int j = 0; j < e[u].size(); j++)
        {
            min_dis[e[u][j].v] = min(min_dis[e[u][j].v], min_dis[u] + e[u][j].w);
            max_dis[e[u][j].v] = max(max_dis[e[u][j].v], max_dis[u] + e[u][j].w);
        }
    }
}
