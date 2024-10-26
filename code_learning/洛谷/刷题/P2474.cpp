#include <bits/stdc++.h>

constexpr int MAXN = 51;

int dmin[MAXN][MAXN], dmax[MAXN][MAXN];

char s[MAXN][MAXN];

int n, a, b;

int ans1, ans2, ans3;

void compute() {
    // 设置初始关系
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '=') {
                dmin[i][j] = 0;
                dmax[i][j] = 0;
            } else if (s[i][j] == '+') {
                dmin[i][j] = 1;
                dmax[i][j] = 2;
            } else if (s[i][j] == '-') {
                dmin[i][j] = -2;
                dmax[i][j] = -1;
            } else {
                dmin[i][j] = -2;
                dmax[i][j] = 2;
            }
        }
    for (int i = 1; i <= n; i++) {
        dmin[i][i] = 0;
        dmax[i][i] = 0;
    }
    // Floyd 算法
    for (int bridge = 1; bridge <= n; bridge++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                dmin[i][j] = std::max(dmin[i][j], dmin[i][bridge] + dmin[bridge][j]);
                dmax[i][j] = std::min(dmax[i][j], dmax[i][bridge] + dmax[bridge][j]);
            }
    // 统计答案
    ans1 = ans2 = ans3 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i != a && i != b && j != a && j != b) {
                if (dmin[a][i] > dmax[j][b] || dmin[a][j] > dmax[i][b])
                    ans1++;
                if (dmax[a][i] < dmin[j][b] || dmax[a][j] < dmin[i][b])
                    ans3++;
                if (dmin[a][i] == dmax[a][i] && dmin[j][b] == dmax[j][b] && dmin[a][i] == dmin[j][b]) {
                    ans2++;
                } else if (dmin[b][i] == dmax[b][i] && dmin[j][a] == dmax[j][a] && dmin[b][i] == dmin[j][a]) {
                    ans2++;
                }
            }
        }
    }
}

void solve() {
    std::cin >> n >> a >> b;
    std::string temp;
    for (int i = 1; i <= n; i++) {
        std::cin >> temp;
        for (int j = 1; j <= n; j++) {
            s[i][j] = temp[j - 1];
        }
    }
    compute();
    std::cout << ans1 << ' ' << ans2 << ' ' << ans3;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}