#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
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
    int ans = 0;
    sort(s.begin(), s.end(),cmp);
    int j = 0, i = 0;
    for (; i < n; i++)
    {
        if (s[i] * p0 >= x)
        {
            ans++;
            continue;
        }
        else
            break;
    }
    for (; j < k; j++)
        while (s[i] * (p[j] - t[j]) >= x)
        {
            ans++;
            i++;
        }
    cout << ans;

    return 0;
}