#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 1)
            ans1 >= ans2 ? ans2 += 1 : ans1 += 1;
        else if (a[i] == 1)
            ans1 += 1;
        else if (b[i] == 1)
            ans2 += 1;
        else if (a[i] == -1 && b[i] == -1)
            ans1 >= ans2 ? ans1 -= 1 : ans2 -= 1;
    }
    cout << min(ans1, ans2) << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}