#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld sml = 1e-9;

int n;
vector<ld> a;

void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    reverse(a.begin(), a.end());
    while (a.size() && a.back() == 1)
        a.pop_back();
    reverse(a.begin(), a.end());

    for (auto &i : a)
    {
        if (i == 1)
        {
            cout << "-1\n";
            return;
        }
        i = log(log(i));
    }

    ll ans = 0;
    for (int i = 1; i < a.size(); i++)
    {
        ld need = a[i - 1] - a[i];
        if (need > sml)
        {
            int cnt = 1 + (need - sml) / log(2);
            ans += cnt;
            a[i] += cnt * log(2);
        }
    }
    cout << ans << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}