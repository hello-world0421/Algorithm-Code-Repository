#include <bits/stdc++.h>

constexpr int MAXN = 1e5 + 1;

int n, k, minc;

int rank[MAXN], temp[MAXN];

std::map<std::string, std::priority_queue<int>> team;

void solve() {
    std::cin >> n >> k;
    minc = INT_MAX;
    for (int i = 1, c; i <= k; i++) {
        std::cin >> c;
        minc = std::min(minc, c);
    }
    int power; std::string belong;
    for (int i = 1; i <= n; i++) {
        std::cin >> power >> belong;
        team[belong].push(power);
        temp[i] = power;
    }
    int cnt = 0;
    for (auto& [belong, power] : team) {
        int siz = power.size();
        for (int i = 1; i <= std::min(minc, siz); i++) {
            rank[++cnt] = power.top();
            power.pop();
        }
    }
    std::sort(rank + 1, rank + 1 + cnt, std::greater<int>());
    for (int i = 1; i <= n; i++) {
        int l = 1, r = cnt, ans = -1, mid;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (temp[i] >= rank[mid]) {
                ans = mid, r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        std::cout << (ans == -1 ? cnt : ans - (rank[ans] != temp[i])) << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}