#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;
int arr[MAXN];

void func()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bool b1 = 0, b2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((!b1) && (!b2))
        {
            if (arr[i] == 0)
                continue;
            ans++;
            if (arr[i] <= 2)
                b1 = 1;
        }
        else if (b1)
        {
            b1 = 0;
            if (arr[i] <= 2)
                continue;
            ans++;
            if (arr[i] <= 4)
                b2 = 1;
        }
        else
        {
            b2 = 0;
            if (arr[i] == 0)
                continue;
            ans++;
            if (arr[i] <= 4)
                b1 = 1;
        }
    }
    cout << ans << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        func();
}