#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 1;

void solve()
{
    int n;
    cin >> n;
    vector<string> grid(2);
    for (int i = 0; i < 2; i++)
        cin >> grid[i];
    int ans = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
        {
            if (j + 2 < n && grid[i][j] == 'x' && grid[i][j + 1] == '.' && grid[i][j + 2] == 'x')
                if (i == 0 && grid[1][j] == '.' && grid[1][j + 1] == '.' && grid[1][j + 2] == '.')
                    ans++;
                else if (i == 1 && grid[0][j] == '.' && grid[0][j + 1] == '.' && grid[0][j + 2] == '.')
                    ans++;
        }
    cout << ans << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}

/*
....x.xxxxx.x
..x..........
*/