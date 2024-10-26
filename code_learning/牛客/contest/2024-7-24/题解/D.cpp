#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

void solve()
{
    // 分别为 num1 和 num2
    string s, t;
    cin >> s >> t;
    // 反转 num1
    reverse(s.begin(), s.end());
    int n = s.size(), m = t.size();
    vector<ll> a(n + m + 10, 0);
    vector<ll> sum(n + 1);
    int k = t[0] - '0';
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + s[i] - '0';
    }
    for (int i = 1; i <= m; i++)
    {
        a[i] += sum[min(i, n)] * k;
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        a[m + i] += (sum[min(n, i + m)] - sum[i]) * k;
        a[m + i + 1] += a[m + i] / 10;
        a[m + i] %= 10;
    }
    int cur = m + n;
    while (a[cur])
    {
        a[cur + 1] += a[cur] / 10;
        a[cur] %= 10;
        cur++;
    }
    while (cur > 1 && !a[cur - 1])
        cur--;
    for (int i = cur - 1; i >= 1; i--)
        cout << a[i];
    if (cur <= 1)
        cout << 0;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); // cout.tie(0);

    solve();

    return 0;
}