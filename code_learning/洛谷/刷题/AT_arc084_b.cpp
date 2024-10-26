#include <bits/stdc++.h>
using pii = std::pair<int, int>;

constexpr int MAXK = 1e5 + 1;

int k;

std::deque<pii> deque;

bool visit[MAXK];

int bfs() {
    deque.clear();
    deque.push_back({ 1, 1 });
    int mod, cost;
    while (!deque.empty()) {
        auto [mod, cost] = deque.front(); deque.pop_front();
        if (!visit[mod]) {
            visit[mod] = true;
            if (mod == 0) {
                return cost;
            }
            deque.push_front({ (mod * 10) % k, cost });
            deque.push_back({ (mod + 1) % k, cost + 1 });
        }
    }
    return -1;
}

void solve() {
    std::cin >> k;
    std::cout << bfs() << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}