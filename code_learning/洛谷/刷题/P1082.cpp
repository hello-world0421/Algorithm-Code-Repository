#include <bits/stdc++.h>
using namespace std;

int d, x, y, tx, ty;

void exgcd(int a, int b) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b);
        tx = x, ty = y;
        x = ty;
        y = tx - ty * (a / b);
    }
}

void solve() {
    int a, b; cin >> a >> b;
    exgcd(a, b);
    cout << (x % b + b) % b << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}