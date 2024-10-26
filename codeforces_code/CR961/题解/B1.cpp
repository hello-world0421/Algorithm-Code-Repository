#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 加快输入的速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 多组测试
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin.tie(nullptr)->sync_with_stdio(0);
        // n 表示鲜花数量，m 表示硬币的数量
        int n;
        int64_t m;
        cin >> n >> m;
        // 字典 mp 的 key 表示花瓣数，value 表示该种花数量
        map<int64_t, int64_t> mp;
        // 数组 a 表示第 i 朵花的花瓣数（价格）
        vector<int64_t> a(n);
        // 读入花瓣数并进行统计
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] += 1;
        }
        // 遍历求解答案
        int64_t ans = 0;
        for (auto &[k, v0] : mp)  // 加上 & 符号后就会创建一个引用而不是拷贝，不仅可以提高性能，而且可以修改 mp 中的值
        {
            auto it = mp.find(k + 1);
            auto v1 = (it != mp.end() ? it->second : 0);
            // v0 flowers with k petals
            // v1 flowers with k + 1 petals
            for (int64_t x = 0; x <= v0; x++)
            {
                if (x * k <= m)
                {
                    auto y = min((m - x * k) / (k + 1), v1);
                    ans = max(ans, x * k + y * (k + 1));
                }
                else
                    break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
