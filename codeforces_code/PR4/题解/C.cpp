#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
int n, a[MAX_N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    bool has_odd = false, has_even = false;
    for (int i = 1; i <= n; i++)
        if (a[i] % 2 == 1)
            has_odd = true;
        else
            has_even = true;
    if (has_even && has_odd)
        cout << -1 << '\n';
    else
    {
        vector<int> operations;
        for (int i = 29; i >= 0; i--)
            operations.push_back(1 << i);
        if (has_even)
            operations.push_back(1);
        cout << operations.size() << '\n';
        for (int x : operations)
            cout << x << ' ';
        cout << '\n';
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}