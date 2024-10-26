#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long mx = 0, sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        mx = max({mx, sum - a[i] + 1ll * a[i] * n, sum - a[i] + a[i] + n});
    }
    cout << mx << '\n';
}