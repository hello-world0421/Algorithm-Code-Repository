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
        int a, b, c;
        cin >> a >> b >> c;
        cout << ((a < b && b > c) ? "PEAK" : ((a < b && b < c) ? "STAIR" : "NONE")) << '\n';
    }
    return 0;
}
