#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = ex_gcd(b, a % b, y, x);
    // x1 = y2
    // y1 = x2 - a / b * y2
    y -= a / b * x;
    return d;
}

ll CRT(int k, ll* a, ll* r) {
    ll n = 1, ans = 0;
    for (int i = 1; i <= k; i++)
        n *= r[i];
    for (int i = 1; i <= k; i++) {
        // m 与 r[i] 互素
        ll m = n / r[i], b, y;
        ex_gcd(m, r[i], b, y); // b * m mod r[i] = 1
        // 不要对 r[i] 取模，而是对 n 直接取模
        ans = (ans + a[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a[4] = { 0, 2, 3, 2 }, r[4] = { 0, 3, 5, 7 };
    cout << CRT(3, a, r);

    return 0;
}