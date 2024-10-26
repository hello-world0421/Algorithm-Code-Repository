#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;

int n;
int a[N];
bool c[N];

void doit()
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[a[i]])
            maxu = max(maxu, a[i]);
        else
            c[a[i]] = true;
        a[i] = maxu;
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    doit();
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    doit();

    for (int i = 1; i <= n; ++i)
        ans += (n - i + 1) * 1LL * a[i];
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
