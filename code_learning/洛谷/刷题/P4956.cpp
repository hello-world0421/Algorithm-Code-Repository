#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n /= 364;
    for (int i = 100; i >= 1; i--)
        if ((n - i) % 3 == 0 && (n - i) / 3 > 0)
        {
            cout << i << '\n'
                 << (n - i) / 3;
            return 0;
        }

    return 0;
}