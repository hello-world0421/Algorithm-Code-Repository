/*
模拟 + 找规律
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    cout << "Yes\n" << n - 1 << '\n';
    int U = x, D = x, L = y, R = y;
    for (int i = 0; i < n - 1; i++) {
        if (U > 1 && L > 1) {
            U--, L--;
            cout << U << ' ' << L << ' ' << D - U << ' ' << R - L << '\n';
        } else if (D < n && L > 1) {
            D++, L--;
            cout << D << ' ' << L << ' ' << U - D << ' ' << R - L << '\n';
        } else if (D < n && R < n) {
            D++, R++;
            cout << D << ' ' << R << ' ' << U - D << ' ' << L - R << '\n';
        } else if (U > 1 && R < n) {
            U--, R++;
            cout << U << ' ' << R << ' ' << D - U << ' ' << L - R << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}