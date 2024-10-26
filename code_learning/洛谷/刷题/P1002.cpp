#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 21;

int main() {
    vector<pair<int, int>> move(4);
    move = { { 1, 2 }, { 1, -2 }, { -1, 2 }, { -1, -2 } };

    ll n, m, mn, mm;
    cin >> n >> m >> mn >> mm;
    ll grid[N][N] = { 0 };
    ll dp[N][N] = { 0 };

    grid[mn][mm] = -1;
    for (int i = 0; i < 4; i++) {
        int dx = move[i].first, dy = move[i].second;
        if (mn + dx <= n && mm + dy <= m && mn + dx >= 0 && mm + dy >= 0)
            grid[mn + dx][mm + dy] = -1;
        if (mn + dy <= n && mm + dx <= m && mn + dy >= 0 && mm + dx >= 0)
            grid[mn + dy][mm + dx] = -1;
    }

    for (int i = 0; i <= n; i++) {
        if (grid[i][0] == -1)
            break;
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; i++) {
        if (grid[0][i] == -1)
            break;
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == -1)
                continue;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n][m];

    return 0;
}