#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        int res = abs(s[i] - s[n - i - 1]);
        ans += min(res, 26 - res);
    }
    cout << ans;

    return 0;
}