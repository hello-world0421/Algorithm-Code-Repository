#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0, j = 1;
    int ans = 0;
    while (i < n && j < n)
    {
        cout << i << ' ' << j;
        while (i < n && (s[i] != '_' || s[i] != '('))
            i++;
        while (j < n && (s[j] != ')' || s[j] != '_'))
            j++;
        ans += (j - i);
        s[i] = '(', s[j] = ')';
        cout << s << '\n';
        i++, j++;
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