#include <bits/stdc++.h>

constexpr int MAXN = 2e5 + 2;
std::queue<std::pair<int, int>> q;
char map[2][MAXN];
bool vis[2][MAXN];
int n;

void solve() {
    std::cin >> n;
    for (int i = 0; i < 2; i++) {
        map[i][0] = map[i][n + 1] = 'x';
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> map[i][j];
        }
    }
    int ans = 0;
    auto get = [&](int pos) {
        int cnt = 0;
        for (int i = 0; i <= n + 1; i++) {
            vis[0][i] = vis[1][i] = false;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = pos; j < pos + 3; j++) {
                if (map[i][j] != 'x' && !vis[i][j]) {
                    vis[i][j] = true;
                    q.push({ i, j });
                    while (!q.empty()) {
                        std::pair<int, int> now = q.front(); q.pop();
                        if (map[now.first ^ 1][now.second] == '.' && !vis[now.first ^ 1][now.second]) {
                            vis[now.first ^ 1][now.second] = true;
                            q.push({ now.first ^ 1, now.second });
                        }
                        if (now.second + 1 < pos + 3 && map[now.first][now.second + 1] == '.' && !vis[now.first][now.second + 1]) {
                            vis[now.first][now.second + 1] = true;
                            q.push({ now.first, now.second + 1 });
                        }
                        if (now.second - 1 >= pos && map[now.first][now.second - 1] == '.' && !vis[now.first][now.second - 1]) {
                            vis[now.first][now.second - 1] = true;
                            q.push({ now.first, now.second - 1 });
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 1, ans1, ans2; j <= n; j++) {
            if (map[i][j] == '.') {
                ans1 = get(j - 1);
                map[i][j] = 'x';
                ans2 = get(j - 1);
                map[i][j] = '.';
                ans += (ans1 != ans2);
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}