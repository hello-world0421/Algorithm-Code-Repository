// I题
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n, x, y, z; std::cin >> n >> x >> y >> z;
    i64 m, cost, type; std::cin >> m;
    std::map<i64, std::priority_queue<i64, std::vector<i64>, std::greater<i64>>> mp;
    for (int i = 0; i < m; i++) {
        std::cin >> cost >> type;
        mp[type].emplace(cost);
    }
    i64 money = x + y * n + z * (n / 30);
    int ans = 0;

    while (money > 0 && !mp.empty()) {
        i64 min_cost = LLONG_MAX, min_type = -1;
        for (auto& [type, pq] : mp) {
            if (!pq.empty() && pq.top() < min_cost) {
                min_cost = pq.top(); min_type = type;
            }
        }
        if (min_cost > money) break;
        money -= min_cost; ans++;
        mp.erase(min_type);
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}