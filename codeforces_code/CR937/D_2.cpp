#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> nums;
    for (int t = 1; t <= 32; t++)
    {
        string s = "";
        for (int i = 5; i >= 0; i--)
        {
            if (t & (1 << i))
            {
                s += "1";
            }
            else
            {
                s += "0";
            }
        }
        nums.push_back(atoi(s.c_str()));
    }
    const int N = int(1e5) + 10;
    vector<bool> can(N, false);
    can[1] = true;
    vector<int> que(1, 1);
    for (int b = 0; b < int(que.size()); b++)
    {
        for (int x : nums)
        {
            if (x <= N / que[b])
            {
                int to = que[b] * x;
                if (to < N && !can[to])
                {
                    can[to] = true;
                    que.push_back(to);
                }
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        cout << (can[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}
