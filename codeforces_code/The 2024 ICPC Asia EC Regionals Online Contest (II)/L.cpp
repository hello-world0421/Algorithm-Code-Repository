#include <bits/stdc++.h>
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return (b == 0 ? a : gcd(b, a % b));
}

i64 n;

double func(i64 t, i64 c) {
    return c / 2.0 + 1.0 * t / c - 0.5;
}

void solve() {
    std::cin >> n;
    i64 c, l, r;
    r = ceil(sqrt(2 * n)); l = r - 1;
    c = (func(n, l) > func(n, r) ? r : l);

    i64 up = c * (c - 1) + 2 * n, down = 2 * c;
    i64 d = gcd(up, down);
    up /= d; down /= d;

    std::cout << up << ' ' << down << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}