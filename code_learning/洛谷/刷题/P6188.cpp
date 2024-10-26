#include <bits/stdc++.h>

int n;

void solve() {
    std::cin >> n;
    for (int a = n / 7; a >= 0; a--) {
        for (int c = (n - 7 * a) / 3, temp; c >= a; c--) {
            temp = n - 7 * a - 3 * c;
            if (temp % 4 == 0 && temp / 4 >= a) {
                std::cout << a << ' ' << temp / 4 << ' ' << c << '\n';
                return;
            }
        }
    }
    std::cout << -1 << '\n';
    return;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}