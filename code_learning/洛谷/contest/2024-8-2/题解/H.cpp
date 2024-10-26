/*
贪心
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // 先遍历字符串求出字符串中的字母数量与数字数量
    int num_n = 0, ch_n = 0;
    for (auto ch : s)
    {
        if (ch >= '0' && ch <= '9')
            num_n++;
        else if (ch >= 'a' && ch <= 'z')
            ch_n++;
    }
    // 贪心
    // 前 num_n 个字符中字母的数量
    int ans = s.length(), res = 0;
    for (int i = 0; i < num_n; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            res++;
    ans = min(ans, res);
    // 前 ch_n 个字符中数字的数量
    res = 0;
    for (int i = 0; i < ch_n; i++)
        if (s[i] >= '0' && s[i] <= '9')
            res++;
    ans = min(ans, res);
    cout << ans;

    return 0;
}