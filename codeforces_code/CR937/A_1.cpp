#include <iostream>

using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && b < c)
        cout << "STAIR" << "\n";
    else if (a < b && b > c)
        cout << "PEAK" << "\n";
    else
        cout << "NONE" << "\n";
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}
