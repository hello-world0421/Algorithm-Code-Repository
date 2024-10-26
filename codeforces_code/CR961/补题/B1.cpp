// 暴力枚举，时间复杂度为：O(n)
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
        vector<int64_t> a(n);
        map<int64_t, int64_t> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        int64_t ans = 0;
        for (auto &[piece, num1] : mp)
        {
            auto it = mp.find(piece + 1);
            auto num2 = (it != mp.end() ? it->second : 0);
            for (int64_t x = 0; x <= num1; x++)
            {
                if (x * piece <= m)
                {
                    auto y = min((m - piece * x) / (piece + 1), num2);
                    ans = max(ans, x * piece + y * (piece + 1));
                }
                else
                    break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}