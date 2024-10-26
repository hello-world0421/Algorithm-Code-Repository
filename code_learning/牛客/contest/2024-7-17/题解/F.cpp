#include "bits/stdc++.h"
using namespace std;
// 时间复杂度是：n*log_2(n)，因为求解过程可以看作 n * 调和级数，所以暴力求解即可
int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum ^= a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n / i; j++)
        {
            ans = max(ans, sum ^ a[i] ^ (a[i] + j));
            ans = max(ans, sum ^ a[i] ^ (1ll * a[i] * j));
        }
    cout << ans << '\n';
    return 0;
}