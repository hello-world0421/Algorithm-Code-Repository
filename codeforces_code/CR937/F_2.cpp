#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c != a + 1)
        {
            cout << -1 << '\n';
        }
        else
        {
            vector<int> v(1, 1);
            int ptr = 0;
            for (int it = 0; it < a + b; it++)
            {
                if (v[ptr] == 0)
                {
                    ptr += 1;
                }
                if (ptr == int(v.size()) - 1)
                {
                    v.push_back(0);
                }
                v[ptr] -= 1;
                v[ptr + 1] += (it < a ? 2 : 1);
            }
            cout << int(v.size()) - 1 << '\n';
        }
    }
    return 0;
}
