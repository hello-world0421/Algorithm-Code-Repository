#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int quick_power(ll a, ll b, int p)
{
    ll ans = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
            ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return (int)ans;
}

int main()
{
    ll a, b;
    int p;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << quick_power(a, b, p);

    return 0;
}