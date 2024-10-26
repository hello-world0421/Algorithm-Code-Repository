/*
宽度优先搜索 (bfs)
时间复杂度 O(nm)
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

int n , m , h , k;
// 数组 mp 用于存储图中各个点的高度
// 数组 tim 用于记录水流流经一个点时的时间戳
// 数组 dis 用于记录起点到各个点的距离
int mp[51][51] , tim[51][51] , dis[51][51];
// 用于移动的变量
vector<int> dx = { 0, 1, 0, -1 } , dy = { 1, 0, -1, 0 };

void solve() {
    // 建图（邻接矩阵）
    cin >> n >> m >> h >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];

    // 先处理水流的运动情况，建立时间戳
    memset(tim , inf , sizeof(tim));
    queue<pair<int , int>> q;
    for (int i = 1; i <= k; i++) {
        int x , y;
        cin >> x >> y;
        q.push({ x, y }) , tim[x][y] = 0;
    }
    while (q.size()) {
        auto [x , y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i] , ty = y + dy[i];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && mp[x][y] > mp[tx][ty] && tim[tx][ty] > tim[x][y] + 1)
                tim[tx][ty] = tim[x][y] + 1 , q.push({ tx, ty });
        }
    }

    // 处理从起点去往各个点的运动情况
    memset(dis , inf , sizeof(dis));
    q.push({ 1, 1 }) , dis[1][1] = 0;
    while (q.size()) {
        auto [x , y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i] , ty = y + dy[i];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && abs(mp[x][y] - mp[tx][ty]) <= h && dis[x][y] + 1 < dis[tx][ty] && dis[x][y] + 1 < tim[tx][ty])
                dis[tx][ty] = dis[x][y] + 1 , q.push({ tx, ty });
        }
    }

    if (dis[n][m] > n * m)
        cout << "No" << '\n';
    else
        cout << "Yes\n"
        << dis[n][m] << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}