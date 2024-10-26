#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        int64_t m;
        cin >> n >> m;
        vector<int64_t> a(n), c(n);
        map<int64_t, int64_t> mp;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            mp[a[i]] = c[i];
        }
        int64_t ans = 0;
        for (auto &[k, v0] : mp)
        {
            auto it = mp.find(k + 1);
            auto v1 = (it != mp.end() ? it->second : 0);
            auto x = min(v0, m / k);
            auto y = min(v1, (m - x * k) / (k + 1));
            auto add = min({x, v1 - y, (m - x * k) % (k + 1)});
            ans = max(ans, x * k + y * (k + 1) + add);
        }
        cout << ans << '\n';
    }

    return 0;
}