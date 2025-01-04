#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<i64, i64>> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i].first;
        w[i].second = i;
    }
    std::sort(w.begin() + 1, w.end(), std::greater<std::pair<i64, i64>>());
    std::vector<i64> adj[n + 1];
    for (int i = 1, u, v; i <= n - 1; i++) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    i64 res = std::accumulate(w.begin() + 1, w.end(), 0LL, [](i64 a, auto& p) {
        return a + p.first;
    }), t = n - 1;
    std::vector<i64> ans;
    ans.push_back(res); t--;
    for (int i = 1; i <= n; i++) {
        while (adj[w[i].second].size() > 1 && t > 0) {
            res += w[i].first;
            adj[w[i].second].pop_back();
            ans.push_back(res); t--;
        }
        if (t == 0) break;
    }
    for (int i = 0; i < n - 1; i++) {
        std::cout << ans[i] << " \n"[i == n - 2];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}