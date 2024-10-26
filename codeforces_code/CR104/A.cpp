#include <bits/stdc++.h>

using namespace std;
const int MAXN = 50;

int n;
string s;
int main()
{
    cin >> n;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '4' && s[i] != '7')
        {
            cout << "NO";
            return 0;
        }
        if (i < n / 2)
            ans += s[i] - '0';
        else
            ans -= s[i] - '0';
    }
    if (ans == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}