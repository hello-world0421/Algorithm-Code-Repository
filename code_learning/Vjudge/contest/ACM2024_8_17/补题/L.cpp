/*
概率dp
时间复杂度 O(wb)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, b; cin >> w >> b;
    // dp[i][j] 表示 i 只白鼠和 j 只黑鼠的情况下赢的概率
    vector<vector<double>> dp(w + 2, vector<double>(b + 2, 0.0));

    for (int i = 1; i <= w; i++)
        dp[i][0] = 1.0, dp[i][1] = (i * 1.0) / (i + 1);
    for (int i = 1; i <= w; i++)
        for (int j = 1; j <= b; j++) {
            // 将各个分支赢的情况都考虑即可
            dp[i][j] = (i * 1.0) / (j + i);
            dp[i][j] += (j * 1.0) / (j + i) * (j - 1 * 1.0) / (j + i - 1) * i / (j + i - 2) * dp[i - 1][j - 2];
            if (j >= 3)
                dp[i][j] += (j * 1.0) / (j + i) * (j - 1) / (j + i - 1) * (j - 2) / (j + i - 2) * dp[i][j - 3];
        }
    cout << fixed << setprecision(12) << dp[w][b] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}