#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;

int n;
int a[N];
int dp[N];
void minh(int &x, int y)
{
    x = min(x, y);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int minu[2] = {N, N};
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if (a[i] == 0)
            minh(dp[i], dp[i - 1]);
        if (a[i] <= 2)
            minh(dp[i], i + minu[1 - i % 2]);

        if (a[i] <= 2)
            minh(minu[i % 2], dp[i - 1] - i);
        else if (a[i] > 4)
            minu[0] = minu[1] = N;
    }

    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}
