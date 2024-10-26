#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, c, d; cin >> n >> c >> d;
    int b, p;
    char m;
    vector<pair<int, int>> C, D;
    for (int i = 1; i <= n; i++) {
        cin >> b >> p >> m;
        if (m == 'C') {
            C.push_back({ b, p });
        } else {
            D.push_back({ b, p });
        }
    }
    int ans = 0;
    sort(C.begin(), C.end(), greater<pair<int, int>>());
    // for (int i = 0; i + 1 < C.size(); i++) {
    //     if (C[i].second + C[i + 1].second <= c) {
    //         ans = max(ans, C[i].first + C[i + 1].first);
    //         break;
    //     }
    // }
    int dp[2][c + 1] = {-INT_MAX};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= C.size(); j++) {
            for (int k = c; k >= C[j].second; k--) {
                if (i == 0) {
                    dp[i][k] = 0;
                    continue;
                }
                dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - C[j].second] + C[j].first);
            }
        }
    }
    cout << dp[2][c];
    // sort(D.begin(), D.end(), greater<pair<int, int>>());
    // for (int i = 0; i + 1 < D.size(); i++) {
    //     if (D[i].second + D[i + 1].second <= d) {
    //         ans = max(ans, D[i].first + D[i + 1].first);
    //         break;
    //     }
    // }
    // for (int i = 0, j = 0; i < C.size() && j < D.size();) {
    //     if (C[i].second <= c && D[i].second <= d) {
    //         ans = max(ans, C[i].first + D[i].first);
    //     }
    // }
    // cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}