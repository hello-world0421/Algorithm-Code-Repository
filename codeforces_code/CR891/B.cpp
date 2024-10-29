#include <bits/stdc++.h>

std::string x;

void solve() {
    std::cin >> x;
    int n = x.length(), k = n;
    for (int i = n - 1; i >= 0; i--) {
        if (x[i] - '0' >= 5) {
            k = i;
            x[i] = '0';
            if (i != 0) {
                x[i - 1] += 1;
            } else {
                x = "1" + x;
                k++; n++;
            }
        }
    }
    for (int i = k; i < n; i++) x[i] = '0';
    std::cout << x << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}