#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x;
    cin >> x;
    int ans = 0;
    while (x)
    {
        if (x == 2)
            x -= 2;
        else if (x % 2)
            x--;
        else
            x /= 2;
        ans++;
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}