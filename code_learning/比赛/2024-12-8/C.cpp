// C题
#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr int MAXN = 2e5 + 2;

i64 cnt2[MAXN];
void init() {
    cnt2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        cnt2[i] = cnt2[i - 1] * 2 % mod;
    }
}

void solve() {
    i64 n; std::cin >> n;
    std::vector<std::pair<i64, i64>> a(n);
    std::vector<bool> ok(n, false);
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].second;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].first > a[i].second) {
            ok[i] = true;
        }
    }
    i64 ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!ok[i]) {
            pq.emplace(a[i].second);
            continue;
        }
        while (!pq.empty() && a[i].first >= pq.top()) {
            cnt++; pq.pop();
        }
        pq.emplace(a[i].second);
        ans = (ans + cnt2[cnt]) % mod;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    init();
    solve();

    return 0;
}