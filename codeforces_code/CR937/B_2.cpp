#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s += ((i + j) % 2 == 0 ? "##" : "..");
            }
            cout << s << '\n';
            cout << s << '\n';
        }
    }
    return 0;
}
