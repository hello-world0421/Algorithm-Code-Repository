#include <bits/stdc++.h>
using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    // 利用 pre 变量来模拟栈 : 表示栈的大小
    int pre = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (pre > 0)
            pre--;
        else
            pre++;
        ans += pre;
        pre += (s[i + 1] == '(' ? 1 : -1);
        ans += pre;
    }
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}
