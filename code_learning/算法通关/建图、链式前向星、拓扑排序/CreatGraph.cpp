#include <bits/stdc++.h>

using namespace std;
// 点的最大数量
const int MAXN = 11;

// 边的最大数量
// 只有链式前向星方式建图需要这个数量
// 注意如果无向图的最大数量是 m 条边，数量要准备 m * 2
// 因为一条无向边要加两条有向边
const int MAXM = 21;

// 邻接矩阵方式建图
int graph1[MAXN][MAXN];

// 不加权的邻接表方式建图
vector<int> graph2[MAXN];
// 加权的邻接表方式建图
vector<pair<int, int>> graph3[MAXN];

// 链式前向星方式建图
int head[MAXN], nxt[MAXM], to[MAXM];

int weight[MAXM]; // 如果边有权重，则需要这个数组

int cnt; // 记号

// 初始化各个存图变量
void build(int n)
{
    // 初始化邻接矩阵
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph1[i][j] = 0;

    // 初始化不加权邻接表
    for (int i = 1; i <= n; i++)
        graph2[i].clear();

    // 初始化加权邻接表
    for (int i = 1; i <= n; i++)
        graph3[i].clear();

    // 链式前向星清空
    cnt = 1;
    memset(head, 0, sizeof(head));
}

// 链式前向星加边
void addEdge(int u, int v, int w)
{
    nxt[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

// 填充有向图
void directGraph(int m)
{
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // 填充有向邻接矩阵
        graph1[u][v] = w;

        // 填充有向不加权邻接表
        graph2[u].push_back(v);

        // 填充有向加权邻接表
        graph3[u].push_back(make_pair(v, w));

        // 链式前向星建图
        addEdge(u, v, w);
    }
}

// 填充无向图
void undirectGraph(int m)
{
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // 填充无向邻接矩阵
        graph1[u][v] = w;
        graph1[v][u] = w;

        // 填充无向不加权邻接表
        graph2[u].push_back(v);
        graph2[v].push_back(u);

        // 填充无向加权邻接表
        graph3[u].push_back(make_pair(v, w));
        graph3[v].push_back(make_pair(u, w));

        // 链式前向星建图
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
}

// 图的遍历函数
void traversal(int n)
{
    // 遍历邻接矩阵
    cout << "Traversing the Adjacency Matrix:" << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << graph1[i][j] << ' ';
        cout << '\n';
    }

    // 遍历邻接表
    cout << "Traversing the Adjacency List:" << '\n';

    // 遍历不加权邻接表
    cout << "unwighted graph:" << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << i << ':' << '\n';
        for (int edge : graph2[i])
            cout << i << ' '
                 << edge << '\n';
        cout << '\n';
    }

    // 遍历加权邻接表
    cout << "wighted graph:" << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << i << ':' << '\n';
        for (auto edge : graph3[i])
            cout << i << ' '
                 << edge.first << ' '
                 << edge.second << '\n';
        cout << '\n';
    }

    // 遍历链式前向星
    cout << "Traversing the Chained Forward Star:" << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        // 对于链式前向星的遍历方式
        for (int edge = head[i]; edge != 0; edge = nxt[edge])
        {
            cout << "(" << to[edge] << "," << weight[edge] << ") ";
        }
        cout << '\n';
    }
}

int main()
{
    build(4);
    directGraph(6);
    traversal(4);

    return 0;
}