#include <bits/stdc++.h>
using namespace std;

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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    return 0;
}