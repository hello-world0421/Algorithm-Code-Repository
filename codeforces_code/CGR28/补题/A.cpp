/*
数论结论：一个数字是11的倍数，当且仅当它的奇数位数字之和与偶数位数字之和的差是11的倍数
所以：删除一个数中的 33 ，不影响该数是不是 33 的倍数
*/
#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::cout << (n % 33 == 0 ? "YES" : "NO") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}