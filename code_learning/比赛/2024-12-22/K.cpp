#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 5e6 + 2;
std::vector<bool> isPrime(MAXN, true);
std::vector<bool> dp(MAXN);

void oula() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        for (int j = i * 2; j < MAXN; j += i)
            isPrime[j] = false;
    }
}

void init() {
    for (int i = 0; i < MAXN; i++) {
        bool ok1 = false, ok2 = false;
        if (isPrime[i]) ok1 = true;
        i64 sum = 0, temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (isPrime[sum]) ok2 = true;
        dp[i] = (ok1 && ok2);
    }
}

void solve() {
    i64 n; std::cin >> n;
    std::cout << (dp[n] ? "Y" : "N");
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    oula();
    init();
    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}