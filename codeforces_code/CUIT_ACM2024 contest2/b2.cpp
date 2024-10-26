#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, k, m;
signed main()
{
    cin >> t;
    while (t-- >= 1)
    {
        int a[N];
        int f[N];
        memset(f, 0, sizeof f);
        memset(a, 0, sizeof a);
        cin >> n >> k >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        multiset<int> se;
        for (int i = 0; i < 2 * n; i++)
        {
            int num = i % n;
            if (se.count(a[num]))
            {
                f[num]++;
                se.erase(se.find(a[num]));
            }
            else
            {
                se.insert(a[num]);
            }
        }
        int n2 = m / (2 * n);
        for (int i = 0; i < n; i++)
        {
            f[i] *= n2;
        }
        for (int i = 0; i < m % (2 * n); i++)
        {
            int num = i % n;
            if (se.count(a[num]))
            {
                f[num]++;
                se.erase(se.find(a[num]));
            }
            else
            {
                se.insert(a[num]);
            }
        }
        for (int i = 0; i < n; i++)
            if (i != n - 1)
                cout << f[i] << " ";
            else
                cout << f[i] << endl;
    }
}
