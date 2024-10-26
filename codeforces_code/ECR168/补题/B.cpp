/*
思维题
*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
        for (int j = 0; j < 2; j++)
            if (s[j][i - 1] == '.' && s[j][i] == '.' && s[j][i + 1] == '.' && s[j ^ 1][i - 1] == 'x' && s[j ^ 1][i] == '.' && s[j ^ 1][i + 1] == 'x')
                ans++;
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