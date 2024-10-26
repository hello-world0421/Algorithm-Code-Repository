#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    cout << (n == 0 ? 1 : (n * n - n + 2)) << ' ';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}