#include <bits/stdc++.h>
using namespace std;

int M = 100001;

vector<int> ok(M + 1, 0);

void init()
{
    ok[1] = 1;
    for (int b = 1; b < M; b++)
    {
        if (!ok[b])
            continue;
        for (int c = b; c < M; c += b)
        {
            int d = c / b;
            bool z = true;
            while (d)
            {
                if (d % 10 > 1)
                {
                    z = false;
                }
                d /= 10;
            }
            if (z)
                ok[c] = 1;
        }
    }
}

void solve()
{
    int N;
    cin >> N;
    cout << (ok[N] ? "YES" : "NO") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--)
        solve();
}
