#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int L, N;
    cin >> L >> N;
    int x;
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        ll res = min(x, L - x + 1);
        ans1 = max(res, ans1);
        ans2 = max(L - res + 1, ans2);
    }
    cout << ans1 << ' ' << ans2;

    return 0;
}