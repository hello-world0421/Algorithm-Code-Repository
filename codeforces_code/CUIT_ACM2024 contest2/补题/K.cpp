#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = 1; i <= n && ans.size() <= n; i++)
        for (int j = 0; i + j * k <= n; j++)
            ans.push_back(i + j * k);
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}