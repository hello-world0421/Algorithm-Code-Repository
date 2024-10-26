#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            if (i * (n - i) <= k)
            {
                cout << i < "\n";
                break;
            }
        }
    }
    return 0;
}
