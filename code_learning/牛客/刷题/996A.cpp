#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ull quick_power(ull a, ull b, ull p)
{
    ull ans = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
            ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans % p;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);

    ull a, b, p;
    cin >> a >> b >> p;
    cout << quick_power(a, b, p);

    return 0;
}