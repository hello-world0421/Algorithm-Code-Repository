/*
模拟 + 位运算 ( 位图 )
时间复杂度 O(n * |s| + m * |T|)
常数时间比使用数组模拟更加的优异
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> intSet(n, 0);
    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (auto ch : s)
            intSet[i] |= (1 << (ch - 'a'));
    }

    int m;
    cin >> m;
    for (int i = 0, ans, temp; i < m; i++)
    {
        cin >> s;
        ans = intSet[s[0] - 'A'];
        for (int j = 1; j + 1 < s.length(); j += 2)
        {
            // 使用位运算模拟集合运算
            temp = intSet[s[j + 1] - 'A'];
            if (s[j] == '+')
                ans |= temp;
            else if (s[j] == '-')
                ans &= (~temp);
            else if (s[j] == '*')
                ans &= temp;
        }
        char j = 'a';
        bool ok = false;
        while (ans > 0)
        {
            if (ans & 1)
                cout << j, ok = true;
            ans >>= 1, j++;
        }
        if (!ok)
            cout << "NO";
        cout << '\n';
    }

    return 0;
}