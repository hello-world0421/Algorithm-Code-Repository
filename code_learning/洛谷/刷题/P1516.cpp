#include <bits/stdc++.h>
using namespace std;

int a, b, m, n, L;

int d, x, y, tx, ty;

void exgcd(int a, int b) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b);
        tx = x; ty = y;
        x = ty;
        y = tx - ty * (a / b);
    }
}

void solve() {
    cin >> a >> b >> m >> n >> L;
    exgcd(m, n);
    x = (x % L + L) % L;
    y = (y % L + L) % L;
    cout << x << ' ' << y << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}