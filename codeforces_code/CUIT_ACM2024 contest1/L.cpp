#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll r, ll limit)
{
    ll ans = 0, y = r;
    for (ll i = 1; i <= r; i++)
    {
        while (i * i + y * y > r * r)
            y--;
        ans += y + 1;
        if (ans * 4ll + 1 >= limit)
            return true;
    }
    return false;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll l = 1, r = n, mid; l <= r;)
    {
        mid = l + ((r - l) >> 1);
        if (check(mid, n))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;

    return 0;
}