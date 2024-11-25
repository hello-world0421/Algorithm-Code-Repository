#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;

constexpr int N = 2e5 + 1;

int n, m;
std::vector<int> power(N);
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> tasks[N];

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> power[i];
    }
    for (int i = 1, start, device, duration, demand; i <= m; i++) {
        std::cin >> start >> device >> duration >> demand;

        while (!tasks[device].empty() && tasks[device].top().first <= start) {
            power[device] += tasks[device].top().second;
            tasks[device].pop();
        }

        if (power[device] >= demand) {
            power[device] -= demand;
            tasks[device].emplace(start + duration, demand);
            std::cout << power[device] << '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}