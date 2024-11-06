#include <bits/stdc++.h>

void solve() {
    std::string s; std::cin >> s;
    int cnt[10] = { 0 };
    for (int i = 0; i < s.length(); i++) {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) {
            std::cout << i << ':' << cnt[i] << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}