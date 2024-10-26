#include <bits/stdc++.h>
using namespace std;

struct UF
{
    int n;
    vector<int> par;
    UF(int _n) : n(_n)
    {
        for (int i = 0; i < n; i++)
            par.push_back(i);
    }
    int find(int a)
    {
        if (a != par[a])
            par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b)
    {
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

void solve()
{
    int N;
    cin >> N;
    vector<vector<string>> z(N, vector<string>(2));
    for (int i = 0; i < N; i++)
    {
        cin >> z[i][0] >> z[i][1];
    }
    vector<vector<int>> ok(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (z[i][0] == z[j][0] || z[i][1] == z[j][1])
            {
                ok[i][j] = 1;
            }
        }
    }
    vector<vector<int>> path(N, vector<int>(1 << N, 0));
    for (int i = 0; i < N; i++)
        path[i][1 << i] = 1;
    int ans = N;
    for (int m = 0; m < (1 << N); m++)
    {
        for (int a = 0; a < N; a++)
        {
            if (path[a][m])
                ans = min(ans, N - __builtin_popcount(m));
            if (!(m & (1 << a)))
                continue;
            for (int b = 0; b < N; b++)
            {
                if (m & (1 << b))
                    continue;
                if (ok[a][b])
                    path[b][m ^ (1 << b)] |= path[a][m];
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}