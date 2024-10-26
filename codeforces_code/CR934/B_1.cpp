#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        k = 2 * k;

        vector<int> a(2 * n), occ(n + 1, 0);

        for (auto &x : a)
            cin >> x;
        for (int i = 0; i < n; i++)
            occ[a[i]]++;

        vector<int> g0, g1, g2;
        for (int i = 1; i <= n; i++)
        {
            if (occ[i] == 0)
                g0.push_back(i);
            else if (occ[i] == 1)
                g1.push_back(i);
            else
                g2.push_back(i);
        }

        int v = 0;
        for (auto x : g2)
        {
            if (v < k)
            {
                v += 2;
                cout << x << " " << x << " ";
            }
        }
        for (auto x : g1)
        {
            if (v < k)
            {
                v++;
                cout << x << " ";
            }
        }
        cout << "\n";

        v = 0;
        for (auto x : g0)
        {
            if (v < k)
            {
                v += 2;
                cout << x << " " << x << " ";
            }
        }
        for (auto x : g1)
        {
            if (v < k)
            {
                v++;
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}