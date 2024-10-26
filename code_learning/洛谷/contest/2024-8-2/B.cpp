#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;
ll pre = 0, a[MAXN], num = 1;

int main()
{
    int n, m;
    cin >> n >> m;
    ll i = 1;
    for (; i < m; i++)
    {
        a[i] = i;
        pre += i;
    }
    while (num * num <= pre && a[i - 1] > num * num - pre)
        num++;
    for (; i <= n; i++)
    {
        a[i] = num * num - pre;
        pre = pre - a[i - m + 1] + a[i];
        num++;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
    return 0;
}