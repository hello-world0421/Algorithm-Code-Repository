#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        x--;
        y--;
        vector<int> a(n, 1);
        int e;
        e = -1;
        for (int i = x + 1; i < n; i++)
        {
            a[i] = e;
            e *= -1;
        }
        e = -1;
        for (int i = y - 1; i >= 0; i--)
        {
            a[i] = e;
            e *= -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << " ";
            cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}
