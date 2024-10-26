// 时间复杂度为 O(n)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 55;

int n;
int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        ++q[x];
    }

    for (int i = 1; i <= n; ++i)
        if (q[i] % 2 == 1)
        {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}
