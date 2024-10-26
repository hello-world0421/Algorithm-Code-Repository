#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// const int MAXN = 1e5 + 5;
// const ll MAXM = 1e18 + 5;
// 1 <= a[i] <= 1e9
ll n, m;

bool check(ll aim, int limit, vector<ll> &a)
{
    if (aim > limit)
        return false;
    ll ans = 0, temp = 0;
    for (ll i = 1, j = 1; i <= n; i++)
    {
        while (a[j] - a[i] <= 1)
        {
            if (temp == 0)
                for (int m = i; m <= j; m++)
                    temp += a[m];
            else
                temp += a[j];
            if (temp > m)
                break;
            ans = max(ans, temp);
            if (ans >= aim && ans <= limit)
                return true;
            if (j + 1 <= n)
                j++;
            else
                break;
        }
        temp = 0;
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    vector<ll> a(n + 1);
    ll sum_a = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum_a += a[i];
    }
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    for (ll l = 0, r = sum_a, mid; l <= r;)
    {
        mid = l + ((r - l) >> 1);
        if (check(mid, m, a))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}