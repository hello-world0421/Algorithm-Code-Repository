/*
循环数组访问索引的技巧
*/
#include "bits/stdc++.h"
#define ll long long
#define endl '\n'
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int nt = 0, nv = 0;
    for (int i = 0; i <= min(n - 1, t); i++)
    {
        if (a[(n - i) % n + 1] > nv)
        {
            nt = i;
            nv = a[(n - i) % n + 1];
        }
    }
    cout << nt << '\n';
    return 0;
}