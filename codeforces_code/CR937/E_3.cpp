#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    string S;
    cin >> N >> S;
    int best = N;
    vector<int> freq(26, 0);
    for (int d = 1; d <= N; d++)
    {
        if (N % d != 0)
            continue;
        int diffs = 0;
        for (int r = 0; r < d; r++)
        {
            int nd = 0;
            int n2 = 0;
            for (int a = r; a < N; a += d)
            {
                int b = S[a] - 'a';
                if (freq[b] == 0)
                    nd++;
                if (freq[b] == 1)
                    n2++;
                freq[b]++;
            }
            for (int a = r; a < N; a += d)
            {
                freq[S[a] - 'a']--;
            }
            if (n2 >= 2 || nd >= 3)
            {
                diffs += 2;
            }
            else if (nd == 2)
            {
                diffs++;
            }
        }
        if (diffs <= 1)
        {
            best = min(best, d);
        }
    }
    cout << best << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}