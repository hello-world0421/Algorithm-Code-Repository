#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2 * 1e5 + 5;
int n, a[MAXN];
bool c[MAXN];

void MAD()
{
    for (int i = 1; i <= n; i++)
        c[i] = false;
    int maxu = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[a[i]])
            maxu = max(maxu, a[i]);
        else
            c[a[i]] = true;
        a[i] = maxu;
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i];
    MAD();
    for (int i = 1; i <= n; i++)
        ans += a[i];
    MAD();
    for (int i = 1; i <= n; i++)
        ans += (n - i + 1) * 1LL * a[i];
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}