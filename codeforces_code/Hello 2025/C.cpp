#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int l, r; std::cin >> l >> r;

    int a = 0, b = 0, c = 0;
    for (int i = 29; i >= 0; i--) {
        if ((l ^ r) >> i & 1) {
            a |= 1 << i;
            b |= (1 << i) - 1;
            break;
        } else {
            a |= l & (1 << i);
            b |= l & (1 << i);
        }
    }
    c = l;
    while (c == a || c == b) c++;
    std::cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}