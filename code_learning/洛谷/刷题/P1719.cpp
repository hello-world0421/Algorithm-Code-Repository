#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int num, pre[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> num;
            pre[i][j] = num + (i == 0 ? 0 : pre[i - 1][j]);
        }

    int dp[n] = { INT_MIN }, ans = INT_MIN, temp[n] = { 0 };

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[k] = pre[j][k] - (i == j ? 0 : pre[i][k]);
                dp[k] = (k == 0 ? temp[k] : max(temp[k], temp[k] + dp[k - 1]));
                ans = max(ans, dp[k]);
            }
        }
    }

    cout << ans;

    return 0;
}