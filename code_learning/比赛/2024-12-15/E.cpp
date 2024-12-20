#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;
    int cnt = 0, ans = INT_MIN;
    std::map<char, int> mp;
    for (int i = 0, j = 0; i < n; i++) {
        if (mp[s[i]]++ == 0) {
            cnt++;
        }
        if (cnt <= k) ans = std::max(ans, i - j + 1);
        else {
            while (cnt > k) {
                mp[s[j]]--; if (mp[s[j++]] == 0) cnt--;
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}