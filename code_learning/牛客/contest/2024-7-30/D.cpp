#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 101;
constexpr int MAXTARGET = 5000;
bool dp[MAXN][MAXTARGET];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> vec[i][j];
    int target;
    cin >> target;
    for (int i = 0; i < m; i++)
        dp[0][vec[0][i]] = true;
    for (int i = 1; i < n; i++)
        for (int k = 1; k < MAXTARGET; k++)
            if (dp[i - 1][k])
                for (int j = 0; j < m; j++)
                    dp[i][k + vec[i][j]] = true;
    int ans = 0xfffffff;
    for (int i = 0; i < MAXTARGET; i++)
        if (dp[n - 1][i])
            ans = min(ans, abs(i - target));
    cout << ans;

    return 0;
}