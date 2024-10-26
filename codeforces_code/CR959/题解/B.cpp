#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size() && s[i] == '0'; ++i)
        if (t[i] != '0')
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}