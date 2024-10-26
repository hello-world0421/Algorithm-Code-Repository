#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2001;
ll dp[MAXN][3];
pair<int, int> point[MAXN];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> point[i].first >> point[i].second;
    }
    dp[0][0] = 0;
    dp[1][0] = 0, dp[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j]
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}