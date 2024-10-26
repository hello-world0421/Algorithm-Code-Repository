// 动态规划，时间复杂度：mn
#include "bits/stdc++.h"
// 代码简化设置
#define ll long long
#define endl '\n'
using namespace std;
// 最大数据量
constexpr int N = 5e3 + 10;
// 题目给定矩阵的翻转矩阵，标定 1 的位置
bool mp[N][N];
// s 变量为矩阵的前缀和矩阵
int s[N][N], dp[N][N];
// 利用前缀和计算一个矩阵区域的公式
int get(int x1, int y1, int x2, int y2)
{
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main()
{
    // 设置输入
    cin.tie(nullptr)->sync_with_stdio(0);
    // 读入数据
    int n, m;
    cin >> n >> m;
    // 读入矩阵信息
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            // y 轴倒着读入数据
            mp[n + 1 - i][j] = (c == '1');
        }
    }
    // 前缀和的计算过程
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
    {
        for (int j = 1; j <= m; j++)
        {
            int k = dp[i - 1][j - 1];
            if (mp[i][j] == 1 && mp[i - k][j] == 1 && mp[i][j - k] == 1 && get(i - k, j - k, i, j) == 3 * k + 1)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else if (mp[i][j] == 1 && mp[i - k + 1][j] == 1 && mp[i][j - k + 1] == 1 && get(i - k + 1, j - k + 1, i, j) == 3 * k - 2)
                dp[i][j] = dp[i - 1][j - 1];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}