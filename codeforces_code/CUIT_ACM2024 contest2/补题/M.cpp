#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, k, x, p0;
    cin >> n >> k >> x >> p0;
    vector<int> s(n), t(k), p(k);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < k; i++)
        cin >> t[i];
    for (int i = 0; i < k; i++)
        cin >> p[i];

    sort(s.begin(), s.end(), cmp);
    int i = 0;

    while (s[i] * p0 >= x)
        i++;
    for (int j = 0; j < k; j++)
        while ((p[j] - t[j]) * s[i] >= x)
            i++;

    cout << i;

    return 0;
}