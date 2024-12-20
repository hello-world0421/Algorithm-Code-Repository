#include <iostream>
#include <vector>

using namespace std;

void moveCarInSpiral(int n, int m) {
    // 定义顺时针方向的移动顺序：右、下、左、上
    vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    vector<char> directionSymbols = { 'R', 'D', 'L', 'U' };  // 对应方向的符号

    // 创建一个 n * m 的网格，标记是否已访问过
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int x = 0, y = 0, dir = 0;  // 初始位置为 (0, 0)，方向为右
    vector<pair<pair<int, int>, char>> corners;  // 记录转角处的坐标和方向

    // 直到所有的节点都被访问
    for (int i = 0; i < n * m; ++i) {
        visited[x][y] = true;

        // 计算下一位置
        int nextX = x + directions[dir].first;
        int nextY = y + directions[dir].second;

        // 如果下一位置超出了边界或者已经被访问过，改变方向
        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextX][nextY]) {
            // 顺时针旋转方向
            dir = (dir + 1) % 4;
            corners.push_back({ {x, y}, directionSymbols[dir] });
            nextX = x + directions[dir].first;
            nextY = y + directions[dir].second;
        }

        // 更新位置
        x = nextX;
        y = nextY;
    }

    // 输出转角处的坐标和方向
    for (auto p : corners) {
        cout << "(" << p.first.first << ", " << p.first.second << ") -> " << p.second << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    moveCarInSpiral(n, m);

    return 0;
}
