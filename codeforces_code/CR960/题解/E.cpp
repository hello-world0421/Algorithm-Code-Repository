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
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            --x, --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> pv(n, -1);
        vector<vector<int>> children(n);
        auto Dfs = [&](auto &&self, int v) -> void
        {
            for (int u : g[v])
                if (u != pv[v])
                {
                    pv[u] = v;
                    children[v].push_back(u);
                    self(self, u);
                }
        };
        Dfs(Dfs, 0);
        auto Ask = [&](int x)
        {
            cout << "? " << x + 1 << endl;
            int got;
            cin >> got;
            return got;
        };
        auto Answer = [&](int x)
        {
            cout << "! " << x + 1 << endl;
        };
        vector<bool> alive(n, true);
        while (true)
        {
            vector<int> leaves;
            for (int i = 0; i < n; i++)
            {
                if (alive[i] && children[i].empty())
                    leaves.push_back(i);
            }
            int cnt = int(leaves.size());
            if (cnt * cnt > n)
            {
                int got = Ask(leaves[0]);
                if (got == 1)
                {
                    Answer(leaves[0]);
                    break;
                }
                for (int x : leaves)
                {
                    alive[x] = false;
                    auto &vec = children[pv[x]];
                    vec.erase(find(vec.begin(), vec.end(), x));
                }
                continue;
            }
            int x = leaves[0];
            vector<int> seq(1, x);
            while (pv[x] != -1 && children[pv[x]].size() == 1)
            {
                x = pv[x];
                seq.push_back(x);
            }
            int got = Ask(x);
            if (got == 1)
            {
                int sz = int(seq.size());
                while (seq.back() != 0)
                    seq.push_back(pv[seq.back()]);
                int low = 0, high = sz - 1;
                while (low < high)
                {
                    int mid = (low + high) >> 1;
                    if (!Ask(seq[mid]))
                    {
                        low = mid + 1;
                        low += 1;
                        high += 1;
                        low = min(low, int(seq.size()) - 1);
                        high = min(high, int(seq.size()) - 1);
                    }
                    else
                        high = mid;
                }
                Answer(seq[low]);
                break;
            }
            for (int y : seq)
                alive[y] = false;
            auto &vec = children[pv[x]];
            vec.erase(find(vec.begin(), vec.end(), x));
        }
    }
    return 0;
}
