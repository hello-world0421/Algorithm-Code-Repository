// 打表找规律
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    ll ans = 0;
    int l = ++b - ++a + 1;
    ans += 3 * (l / 4);
    for (int i = 0; i < l % 4; i++)
        if (a + i < 0 && (a + i) % 4 != -1)
            ans++;
        else if (a + i >= 0 && (a + i) % 4 != 3)
            ans++;
    cout << ans;

    return 0;
}