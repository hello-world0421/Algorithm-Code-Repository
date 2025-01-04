#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<int> a(26, 0);
    for (auto& ch : s) {
        a[ch - 'a']++;
    }
    std::string ans = "";
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < 26; i++) {
            if (a[i] > 0) {
                ans += 'a' + i;
                a[i]--;
                ok = true;
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}