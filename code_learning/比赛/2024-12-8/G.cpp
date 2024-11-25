# G题
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> hp(n + 1), ep(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> hp[i];
    }
    int gong[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            gong[i][j] = 0;
        }
    }
    while (m--) {
        for (int i = 1; i <= n; i++) {
            char type; std::cin >> type;
            if (type == 'P') {
                if (hp[i] <= 0) {
                    continue;
                }
                ep[i]++;
            } else if (type == 'D') {
                int k; std::cin >> k;
                if (hp[i] <= 0) {
                    continue;
                }
                if (ep[i] >= k) {
                    ep[i] -= k; dp[i] = k + 2;
                } else {
                    ep[i] = 0; hp[i]--;
                }
            } else if (type == 'E') {
                int k; std::cin >> k;
                if (hp[i] <= 0) {
                    continue;
                }
                if (ep[i] >= k) {
                    ep[i] -= k;
                    for (int j = 1; j <= n; j++) {
                        if (j != i) gong[i][j] = (k >> 1);
                    }
                } else {
                    ep[i] = 0; hp[i]--;
                }
            } else if (type == 'A') {
                int k, x; std::cin >> k >> x;
                if (hp[i] <= 0) {
                    continue;
                }
                if (ep[i] >= k) {
                    ep[i] -= k;
                    gong[i][x] = k;
                } else {
                    ep[i] = 0; hp[i]--;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (gong[i][j] == 0) continue;
                if (gong[j][i] == 0) {
                    if (dp[j] > 0) {
                        if (dp[j] >= gong[i][j]) {
                            dp[j] -= gong[i][j];
                        } else {
                            hp[j] -= gong[i][j] - dp[j]; dp[j] = 0;
                        }
                    } else {
                        hp[j] -= gong[i][j];
                    }
                    gong[i][j] = 0;
                } else {
                    if (gong[i][j] > gong[j][i]) {
                        hp[j] -= gong[i][j] - gong[j][i];
                    } else {
                        hp[i] -= gong[j][i] - gong[i][j];
                    }
                    gong[i][j] = 0; gong[j][i] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
        }
    }
    i64 cnt = 0, ans = -1;
    for (int i = 1; i <= n; i++) {
        if (hp[i] > 0) {
            cnt++; ans = i;
        }
    }
    if (cnt == 1) {
        std::cout << ans << '\n';
    } else if (cnt == 0) {
        std::cout << "draw\n";
    } else if (cnt > 1) {
        std::cout << "continue\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}