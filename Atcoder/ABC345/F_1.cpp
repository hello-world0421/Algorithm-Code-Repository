#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> G(N);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    int Y = 0;
    vector<int> ans, vis(N), lamp(N);
    for (int i = 0; i < N; i++)
    {
        auto dfs = [&](auto rc, int c) -> void
        {
            vis[c] = 1;
            for (auto &[d, id] : G[c])
            {
                if (vis[d])
                    continue;
                rc(rc, d);
                if (lamp[d] == 0 and Y < K)
                {
                    Y -= lamp[d] + lamp[c];
                    lamp[d] ^= 1, lamp[c] ^= 1;
                    Y += lamp[d] + lamp[c];
                    ans.push_back(id);
                }
            }
        };
        if (!vis[i])
            dfs(dfs, i);
    }

    if (K != Y)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++)
            cout << (i ? " " : "") << ans[i];
        cout << endl;
    }
}
