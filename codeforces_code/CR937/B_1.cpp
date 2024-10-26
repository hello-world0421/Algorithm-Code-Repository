#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            cout << (i / 2 + j / 2 & 1 ? '.' : '#');
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}

// 表达式 (num & 1) 可以用于判断 num 是否为偶数，是则返回0，不是则返回1，与表达式 (num % 2) 类似
