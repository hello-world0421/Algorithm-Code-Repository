#include <bits/stdc++.h>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    // 记录经过车站 x 的公交车编号
    unordered_map<int, vector<int>> stop_to_buses;
    for (int i = 0; i < routes.size(); i++) {
        for (int x : routes[i]) {
            stop_to_buses[x].push_back(i);
        }
    }

    // 小优化：如果没有公交车经过起点或终点，直接返回
    if (!stop_to_buses.count(source) || !stop_to_buses.count(target))
        // 注意原地 TP 的情况
        return source != target ? -1 : 0;

    // BFS
    unordered_map<int, int> dis;
    dis[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int x = q.front(); // 当前在车站 x
        q.pop();
        int dis_x = dis[x];
        for (int i : stop_to_buses[x]) { // 遍历所有经过车站 x 的公交车 i
            for (int y : routes[i]) { // 遍历公交车 i 的路线
                if (!dis.count(y)) { // 没有访问过车站 y
                    dis[y] = dis_x + 1; // 从 x 站上车然后在 y 站下车
                    q.push(y);
                }
            }
            routes[i].clear(); // 标记 routes[i] 遍历过
        }
    }

    return dis.count(target) ? dis[target] : -1;
}