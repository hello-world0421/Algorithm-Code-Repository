#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

constexpr int MAXN = 5e3 + 5;
bool mp[MAXN][MAXN];
int s[MAXN][MAXN];

int get(int x1, int y1, int x2, int y2)
{
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            mp[n + 1 - i][j] = (c == '1');
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = (mp[i][j] == 1);
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
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