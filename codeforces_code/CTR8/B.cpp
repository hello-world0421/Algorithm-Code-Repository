// 构造问题，时间复杂度为：O(n)
// 唯一的构造可能
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> p(n), has(n + 1);
    int mex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            p[i] = mex;
        else
            p[i] = mex - a[i];
        has[p[i]] = true;
        while (has[mex])
            mex++;
    }
    for (int i : p)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}