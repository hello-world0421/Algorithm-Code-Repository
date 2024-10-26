#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (C != A + 1)
    {
        cout << -1 << '\n';
        return;
    }
    priority_queue<int, vector<int>, greater<int>> leaves;
    leaves.push(0);
    for (int i = 0; i < A; i++)
    {
        int v = leaves.top();
        leaves.pop();
        leaves.push(v + 1);
        leaves.push(v + 1);
    }
    for (int i = 0; i < B; i++)
    {
        int v = leaves.top();
        leaves.pop();
        leaves.push(v + 1);
    }
    int ans = 0;
    while (!leaves.empty())
    {
        ans = max(ans, leaves.top());
        leaves.pop();
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}