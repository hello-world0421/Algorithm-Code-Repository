#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    i64 oddSum = 0, evenSum = 0, oddCnt = 0, evenCnt = 0;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        if (i & 1) {
            oddSum += x; oddCnt++;
        } else {
            evenSum += x; evenCnt++;
        }
    }
    bool oddPart = oddSum % oddCnt == 0;
    bool evenPart = evenSum % evenCnt == 0;
    bool connected = oddSum / oddCnt == evenSum / evenCnt;
    std::cout << (oddPart && evenPart && connected ? "YES\n" : "NO\n");
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}