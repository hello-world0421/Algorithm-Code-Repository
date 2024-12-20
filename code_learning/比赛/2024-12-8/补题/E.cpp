// E题
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m, a, b, k; std::cin >> n >> m >> a >> b >> k;
    int max = std::max(n, m), min = std::min(n, m);

    std::function<int(int, int, int)> huihuan = [&](int x, int y, int b) {
        if (b == 0) return x;
        if (x == 0 || y == 0) return 0;
        return x + huihuan(y - 1, x, b - 1);
    };

    int max_cover = a >= min ? max * min : max * (a - 1) + huihuan(max, min - a + 1, b);
    if (max_cover < k) { std::cout << "NO\n"; return; }
    std::cout << "YES\n";

    if (a >= min || a * max >= k) {
        std::string direction = n > m ? "D" : "R";
        for (int i = 0, x = 1, y = 1; i < b; i++) {
            if (y % (m + 1) == 0) { x++; y = 1; }
            std::cout << x << ' ' << y << ' ' << direction << '\n';
            y++;
        }
        for (int i = 0, x = 1, y = 1; i < a; i++) {
            if (k >= max) {
                k -= max;
                std::cout << x << ' ' << y << ' ' << direction << '\n';
                x++;
            } else if (k > 0) {
                std::cout << x << ' ' << max - k + 1 << ' ' << direction << '\n';
                k = 0;
            } else {
                std::cout << 1 << ' ' << 1 << ' ' << direction << '\n';
            }
        }
    } else if (m >= n) {
        std::vector<std::pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        std::vector<char> directionSymbols = { 'R', 'D', 'L', 'U' };

        int ty = 0;
        std::vector<std::pair<std::pair<int, int>, char>> corners;
        for (ty = 0; ty < m; ty++) {
            std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
            corners.clear();

            int x = a - 1, y = ty, dir = 0;
            int tk = k - (a - 1) * m;
            for (int i = 0; i < a - 1; i++)
                for (int j = 0; j < m; j++)
                    visited[i][j] = true;

            while (tk > 0) {
                visited[x][y] = true; tk--;

                int nextX = x + directions[dir].first;
                int nextY = y + directions[dir].second;

                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextX][nextY]) {
                    dir = (dir + 1) % 4;
                    corners.push_back({ {x, y}, directionSymbols[dir] });
                    nextX = x + directions[dir].first;
                    nextY = y + directions[dir].second;
                }

                if (tk > 0) {
                    x = nextX; y = nextY;
                }
            }
            if (x == corners[corners.size() - 1].first.first && y == corners[corners.size() - 1].first.second) {
                break;
            }
        }
        std::vector<std::vector<char>> tags(n, std::vector<char>(m, '#'));
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        corners.clear();

        int x = a - 1, y = ty, dir = 0;
        int tk = k - (a - 1) * m;
        for (int i = 0; i < a - 1; i++)
            for (int j = 0; j < m; j++) {
                visited[i][j] = true;
                tags[i][j] = 'R';
            }

        while (tk > 0) {
            visited[x][y] = true; tk--;

            int nextX = x + directions[dir].first;
            int nextY = y + directions[dir].second;

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextX][nextY]) {
                dir = (dir + 1) % 4;
                corners.push_back({ {x, y}, directionSymbols[dir] });
                nextX = x + directions[dir].first;
                nextY = y + directions[dir].second;
            }
            tags[x][y] = directionSymbols[dir - (tk > 0 ? 0 : 1)];

            if (tk > 0) {
                x = nextX; y = nextY;
            }
        }
        for (int i = 0; i < corners.size(); i++) {
            std::cout << corners[i].first.first + 1 << ' ' << corners[i].first.second + 1 << ' ' << corners[i].second << '\n';
            visited[corners[i].first.first][corners[i].first.second] = true;
            tags[corners[i].first.first][corners[i].first.second] = '#';
        }
        for (int i = 0, x = 0, y = 0; i < b - corners.size(); i++) {
            while (tags[x][y] == '#') {
                if (++y >= m) {
                    y = 0; x++;
                }
            }
            std::cout << x + 1 << ' ' << y + 1 << ' ' << tags[x][y] << '\n';
            if (++y >= m) {
                y = 0; x++;
            }
        }
        for (int i = 0; i < a - 1; i++) {
            std::cout << i + 1 << ' ' << 1 << ' ' << tags[i][0] << '\n';
        }
        std::cout << a << ' ' << ty + 1 << ' ' << tags[a - 1][ty] << '\n';
    } else {
        std::vector<std::pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        std::vector<char> directionSymbols = { 'D', 'R', 'U', 'L' };

        int tx = 0;
        std::vector<std::pair<std::pair<int, int>, char>> corners;
        for (tx = 0; tx < m; tx++) {
            std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
            corners.clear();

            int x = tx, y = a - 1, dir = 0;
            int tk = k - (a - 1) * n;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < a - 1; j++)
                    visited[i][j] = true;

            while (tk > 0) {
                visited[x][y] = true; tk--;

                int nextX = x + directions[dir].first;
                int nextY = y + directions[dir].second;

                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextX][nextY]) {
                    dir = (dir + 1) % 4;
                    corners.push_back({ {x, y}, directionSymbols[dir] });
                    nextX = x + directions[dir].first;
                    nextY = y + directions[dir].second;
                }

                if (tk > 0) {
                    x = nextX; y = nextY;
                }
            }
            if (x == corners[corners.size() - 1].first.first && y == corners[corners.size() - 1].first.second) {
                break;
            }
        }
        std::vector<std::vector<char>> tags(n, std::vector<char>(m, '#'));
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        corners.clear();

        int x = tx, y = a - 1, dir = 0;
        int tk = k - (a - 1) * m;
        for (int i = 0; i < a - 1; i++)
            for (int j = 0; j < m; j++) {
                visited[i][j] = true;
                tags[i][j] = 'D';
            }

        while (tk > 0) {
            visited[x][y] = true; tk--;

            int nextX = x + directions[dir].first;
            int nextY = y + directions[dir].second;

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextX][nextY]) {
                dir = (dir + 1) % 4;
                corners.push_back({ {x, y}, directionSymbols[dir] });
                nextX = x + directions[dir].first;
                nextY = y + directions[dir].second;
            }
            tags[x][y] = directionSymbols[dir - (tk > 0 ? 0 : 1)];

            if (tk > 0) {
                x = nextX; y = nextY;
            }
        }
        for (int i = 0; i < corners.size(); i++) {
            std::cout << corners[i].first.first + 1 << ' ' << corners[i].first.second + 1 << ' ' << corners[i].second << '\n';
            visited[corners[i].first.first][corners[i].first.second] = true;
            tags[corners[i].first.first][corners[i].first.second] = '#';
        }
        for (int i = 0, x = 0, y = 0; i < b - corners.size(); i++) {
            while (tags[x][y] == '#') {
                if (++y >= m) {
                    y = 0; x++;
                }
            }
            std::cout << x + 1 << ' ' << y + 1 << ' ' << tags[x][y] << '\n';
            if (++y >= m) {
                y = 0; x++;
            }
        }
        for (int i = 0; i < a - 1; i++) {
            std::cout << 1 << ' ' << i + 1 << ' ' << tags[0][i] << '\n';
        }
        std::cout << tx + 1 << ' ' << a << ' ' << tags[tx][a - 1] << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}