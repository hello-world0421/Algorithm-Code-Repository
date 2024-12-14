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
    std::vector<i64> a;
    for (auto [type, cost] : mp) {
        a.push_back(cost.top());
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (money >= a[i]) {
            money -= a[i]; ans++;
        } else {
            break;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}