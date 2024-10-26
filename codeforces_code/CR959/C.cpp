#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAXN = 2 * 1e5 + 5;

int a[MAXN];
ll pre_sum[MAXN];
int ans;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pre_sum[i] = pre_sum[i - 1] + a[i];
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (pre_sum[i] - pre_sum[j - 1] > x)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}