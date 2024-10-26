#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pow(int x, int k)
{
    int res = 1;
    for (int i = 1; i <= k; i++)
        res *= x;
    return res;
}

void solve()
{
    int a, b, l;
    cin >> a >> b >> l;
    set<int> se;
    for (int i = 0; pow(a, i) <= l; i++)
        for (int j = 0; pow(b, j) <= l; j++)
            if (l % pow(a, i) == 0 && (l / pow(a, i)) % pow(b, j) == 0)
                se.insert(l / pow(a, i) / pow(b, j));
    cout << se.size() << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}