#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#define MAX_K 500
#define INF (long long)2e+18

int main(void)
{
    int n, k;
    long long c, v;
    long long dp[MAX_K + 1][2][2];

    cin >> n >> k;
    rep(j, k + 1) rep(ii, 2)
    {
        dp[j][ii][0] = -1;
        dp[j][ii][1] = -INF;
    }
    dp[0][0][0] = 0, dp[0][0][1] = 0;

    rep(i, n)
    {
        cin >> c >> v;

        for (int j = k; j >= 1; j--)
        {
            if (dp[j][0][0] != c)
            {
                dp[j][0][0] = c;
                dp[j][0][1] += v;
            }
            else
            {
                dp[j][0][0] = c;
                dp[j][0][1] = dp[j][1][1] + v;
            }
            dp[j][1][0] = -1;
            dp[j][1][1] = -INF;
            rep(kk, 2)
            {
                if (dp[j - 1][kk][1] >= dp[j][0][1])
                {
                    if (dp[j - 1][kk][0] != dp[j][0][0])
                    {
                        dp[j][1][0] = dp[j][0][0];
                        dp[j][1][1] = dp[j][0][1];
                    }
                    dp[j][0][0] = dp[j - 1][kk][0];
                    dp[j][0][1] = dp[j - 1][kk][1];
                }
                else if ((dp[j - 1][kk][1] >= dp[j][1][1]) && (dp[j - 1][kk][0] != dp[j][0][0]))
                {
                    dp[j][1][0] = dp[j - 1][kk][0];
                    dp[j][1][1] = dp[j - 1][kk][1];
                }
            }
        }
        if (dp[0][0][0] != c)
        {
            dp[0][0][0] = c;
            dp[0][0][1] += v;
        }
        else
        {
            dp[0][0][1] = -INF;
        }
    }

    if (dp[k][0][1] < 0)
        cout << "-1" << endl;
    else
        cout << dp[k][0][1] << endl;
    return 0;
}
