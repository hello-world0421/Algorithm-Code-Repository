#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 每一次调用 a b 的值只会变小，一般不会溢出
int ex_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = ex_gcd(b, a % b, y, x);
    // x1 = y2
    // y1 = x2 - a / b * y2
    y -= a / b * x;
    return d;
}

bool liEu(int a, int b, int c, int& x, int& y) {
    int d = ex_gcd(a, b, x, y);
    if (c % d != 0)
        return false;
    int k = c / d;
    x *= k;
    y *= k;
    return true;
}

void solve() {
    int a, b; cin >> a >> b;
    int x, y;
    if (liEu(a, b, 1, x, y)) {
        cout << (x + b) % b;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}