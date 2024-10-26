// 采用三重循环暴力枚举，最坏时间复杂度：m * n
#include "bits/stdc++.h"
// 代码简化设置
#define ll long long
#define endl '\n'
using namespace std;
// 最大数据量
constexpr int N = 5e3 + 10;
// 标记 1 的位置
bool mp[N][N];
// 数据矩阵的前缀和矩阵
int s[N][N];
// 求解区域矩阵的公式
int get(int x1, int y1, int x2, int y2)
{
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main()
{
    // 优化输入设置
    cin.tie(nullptr)->sync_with_stdio(0);
    // 输入数据
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            mp[n + 1 - i][j] = (c == '1');
        }
    }
    // 计算出前缀和矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = (mp[i][j] == 1);
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            // 要连续满足箭头矩阵，该循环才会继续，否则大多数情况，该循环都会在第一次就提前终止
            // 该循环的条件极其苛刻
            for (int k = 1; k <= min(n, m); k++)
            {
                if (i + k - 1 > n || j + k - 1 > m)
                    break;
                if (mp[i + k - 1][j + k - 1] == 1 && mp[i][j + k - 1] == 1 && mp[i + k - 1][j] == 1 && get(i, j, i + k - 1, j + k - 1) == 3 * k - 2)
                    ans = max(ans, k);
                else
                    break;
            }
    cout << ans << endl;
    return 0;
}