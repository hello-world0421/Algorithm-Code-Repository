#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
signed main()
{
    cin >> t;
    while (t-- >= 1)
    {
        int br, bp, bs, dr, dp, ds;
        cin >> br >> bp >> bs;
        cin >> dr >> dp >> ds;
        int sum = 0;
        // cout << min(ds, bp) << min(dp, br) << min(dr, bs);
        // cout << sum << endl;
        int a = min(ds, bp);
        int b = min(dp, br);
        int c = min(dr, bs);
        sum = a + b + c;
        ds -= a;
        bp -= a;
        dp -= b;
        dr -= c;
        bs -= c;
        br -= b;
        // cout << ds << " " << br << " " << dr << " " << bp << " " << dp << " " << bs;
        int mip = min(bp, dp);
        bp -= mip;
        dp -= mip;
        int mis = min(bs, ds);
        bs -= mis;
        ds -= mis;
        int mir = min(br, dr);
        dr -= mir;
        br -= mir;
        // cout << ds << " " << br << " " << dr << " " << bp << " " << dp << " " << bs << '\n';
        sum = sum + (-br) + (-bp) + (-bs);
        cout << sum << endl;
    }
}