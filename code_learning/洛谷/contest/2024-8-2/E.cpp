#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int ti[N][N], vis[N][N], a[N][N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m, k, p;
int ans = 1e9;
void dfs(int x, int y, int dep)
{
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx <= n && xx >= 0 && yy <= m && yy >= 0 && a[x][y] > a[xx][yy])
        {
            if (ti[xx][yy] != 0)
            {
                ti[xx][yy] = min(ti[xx][yy], dep);
            }
            else
            {
                ti[xx][yy] = dep;
            }
            dfs(xx, yy, dep + 1);
        }
    }
}
void ddfs(int x, int y, int dep)
{
    if (x == n && y == m)
    {
        // cout << x << " ++ " << y << endl;
        ans = min(ans, dep - 1);
        // cout << ans << endl;
        return;
    }
    // cout << x << " " << y << " " << dep << endl;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        // cout << 1 << endl;
        int xx = x + dx[i], yy = y + dy[i];
        if (xx <= n && xx >= 1 && yy <= m && yy >= 1 && abs(a[x][y] - a[xx][yy]) <= k && vis[xx][yy] == 0)
        {

            if (ti[xx][yy] != 0)
            {
                if (dep < ti[xx][yy])
                {
                    ddfs(xx, yy, dep + 1);
                }
            }
            else
            {
                ddfs(xx, yy, dep + 1);
            }
        }
    }
    vis[x][y] = 0;
}
signed main()
{

    cin >> n >> m >> k >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    while (p--)
    {

        int x, y;
        cin >> x >> y;
        ti[x][y] = 1;
        dfs(x, y, 1);
    }

    memset(vis, 0, sizeof(vis));
    ddfs(1, 1, 1);
    if (ans != 1e9)
    {
        cout << "Yes" << endl;
        cout << ans << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}