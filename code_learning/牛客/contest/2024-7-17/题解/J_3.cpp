// 用二维哈希加二分处理，二分边长暴力 check
#include "bits/stdc++.h"
// 简化设置
#define ll long long
#define uint unsigned int
#define endl '\n'
using namespace std;
// 设置最大数据量和两个互质数（用于构建二维哈希算法）
constexpr int N = 5e3 + 10, base1 = 131, base2 = 233;
// 标记 1 的位置
char mp[N][N];
uint h[N][N], p1[N], p2[N], s[N][N];
int n, m;
uint gethash(int x1, int y1, int x2, int y2)
{
    return h[x2][y2] - h[x2][y1 - 1] * p1[y2 - y1 + 1] - h[x1 - 1][y2] * p2[x2 - x1 + 1] + h[x1 - 1][y1 - 1] * p1[y2 - y1 + 1] * p2[x2 - x1 + 1];
}
uint gets(int x1, int y1, int x2, int y2)
{
    return s[x2][y2] - s[x2][y1 - 1] * p1[y2 - y1 + 1] - s[x1 - 1][y2] * p2[x2 - x1 + 1] + s[x1 - 1][y1 - 1] * p1[y2 - y1 + 1] * p2[x2 - x1 + 1];
}
void init(int n, int m)
{
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= max(n, m); i++)
    {
        p1[i] = p1[i - 1] * base1;
        p2[i] = p2[i - 1] * base2;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            h[i][j] = h[i][j - 1] * base1 + mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            h[i][j] += h[i - 1][j] * base2;
        }
    }
    int k = min(n, m);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            char c;
            if (i == k || j == 1 || (i + j == k + 1))
                c = '1';
            else
                c = '0';
            s[i][j] = s[i][j - 1] * base1 + c;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            s[i][j] += s[i - 1][j] * base2;
        }
    }
}
bool check(int len)
{
    int k = min(n, m);
    for (int i = 1; i <= n - len + 1; i++)
    {
        for (int j = 1; j <= m - len + 1; j++)
        {
            uint cur = gethash(i, j, i + len - 1, j + len - 1);
            uint res = gets(k - len + 1, 1, k, len);
            if (cur == res)
                return 1;
        }
    }
    return 0;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    init(n, m);
    int l = 0, r = min(n, m);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}