#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        x--, y--;
        vector<int> a(n, 1);
        for (int i = x + 1; i < n; i++)
            a[i] = (i - x) & 1 ? -1 : 1;
        
        for (int i = y - 1; i >= 0; i--)
            a[i] = (y - i) & 1 ? -1 : 1;
        
        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }

    return 0;
}