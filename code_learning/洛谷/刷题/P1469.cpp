#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int num, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ans ^= num;
    }
    cout << ans;

    return 0;
}