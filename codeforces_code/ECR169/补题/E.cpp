#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MAXN = 1e7;
int sg[MAXN + 1];
std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n; std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        ans ^= sg[a];
    }
    std::cout << (ans != 0 ? "Alice\n" : "Bob\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(MAXN);
    sg[0] = 0; sg[1] = 1; sg[2] = 0;
    for (int i = 1; i < primes.size(); i++) {
        sg[primes[i]] = i + 1;
    }
    for (int i = 4; i <= MAXN; i++) {
        sg[i] = sg[minp[i]];
    }
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}