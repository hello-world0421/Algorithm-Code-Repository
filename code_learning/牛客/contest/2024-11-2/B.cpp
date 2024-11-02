#include <bits/stdc++.h>

void solve() {
    std::string s; std::cin >> s;
    int a[10] = { 0 };
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - '0']++;
    }
    for (int i = 0; i <= 9; i++) {
        if (a[i] > 0) {
            std::cout << i << ':' << a[i] << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();
}