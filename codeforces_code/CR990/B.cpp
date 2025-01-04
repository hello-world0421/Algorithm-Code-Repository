#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<int> a(26, 0);
    for (auto c : s) a[c - 'a']++;
    int max_index = -1, min_index = -1, max_val = INT_MIN, min_val = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (a[i] == 0) continue;
        if (a[i] >= max_val) {
            max_val = a[i]; max_index = i;
        }
        if (a[i] < min_val) {
            min_val = a[i]; min_index = i;
        }
    }
    for (int i = 0, t = 1; i < n; i++) {
        if (t > 0 && s[i] - 'a' == min_index) {
            std::cout << char('a' + max_index);
            t--;
        } else {
            std::cout << s[i];
        }
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}