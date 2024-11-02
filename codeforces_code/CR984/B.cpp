#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; std::cin >> n >> k;
    std::cout << n << k;
    map<int, int> mp;
    for (int i = 0, brand, cost; i < k; i++) {
        std::cin >> brand >> cost;
        mp[brand] += cost;
    }
    std::cout << 1 << '\n';
    for (auto& [brand, cost] : mp) {
        std::cerr << brand << ':' << cost << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}