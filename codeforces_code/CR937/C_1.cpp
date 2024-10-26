#include <bits/stdc++.h>

using namespace std;

//
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
// 这段代码的主要功能是根据条件编译来决定是否包含调试工具文件，并根据情况定义debug(...)宏

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int h, m;
        char c;
        cin >> h >> c >> m;
        string s = " AM";
        if (h >= 12)
        {
            h -= 12;
            s = " PM";
        }
        if (h == 0)
        {
            h = 12;
        }
        cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << s << '\n';
    }
    return 0;
}
