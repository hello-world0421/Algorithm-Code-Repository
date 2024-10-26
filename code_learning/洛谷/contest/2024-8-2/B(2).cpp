#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 1e6 + 10;
int n, m;
int pre[N], a[N];

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        a[i] = i;
        pre[i] = pre[i - 1] + a[i];
    }
    // for (int i = 1; i <= m; i++){
    //     cout << a[i] << " ";
    // }

    int num = 2;
    for (int i = m; i <= n; i++)
    {
        int l = num - 1, r = 1e6+1;
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            if (mid * mid - pre[i - 1] + pre[i - m] > a[i - 1])
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        num = r;
        a[i] = num * num - pre[i - 1] + pre[i - m];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}