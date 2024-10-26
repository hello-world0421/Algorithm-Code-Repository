#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 55;

int n;
int a[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] & 1)
        {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}