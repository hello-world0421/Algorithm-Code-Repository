/*
模拟
时间复杂度 O(n * |s| + m * |T|)
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 优化读入方式
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<vector<bool>> chSet(n, vector<bool>(26, false));
    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (auto ch : s)
            chSet[i][ch - 'a'] = true;
    }

    int m;
    cin >> m;
    string op;
    vector<bool> ans = chSet[op[0] - 'A'], temp;

    for (int i = 1; i <= m; i++)
    {
        cin >> op;
        ans = chSet[op[0] - 'A'];
        for (int i = 1; i + 1 < op.length(); i += 2)
        {
            // 模拟集合运算
            temp = chSet[op[i + 1] - 'A'];
            if (op[i] == '+')
                for (int i = 0; i < 26; i++)
                    ans[i] = ans[i] | temp[i];
            else if (op[i] == '-')
                for (int i = 0; i < 26; i++)
                    ans[i] = ans[i] & (~temp[i]);
            else if (op[i] == '*')
                for (int i = 0; i < 26; i++)
                    ans[i] = ans[i] & temp[i];
        }

        bool ok = false;
        for (char i = 'a'; i <= 'z'; i++)
            if (ans[i - 'a'])
                cout << i, ok = true;
        if (!ok)
            cout << "NO";
        cout << '\n';
    }

    return 0;
}