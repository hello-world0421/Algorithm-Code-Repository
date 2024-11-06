#include <bits/stdc++.h>
using i64 = long long;
using string_cnt = std::pair<std::string, int>;

void solve() {
    std::string s;
    std::map<std::string, int> mp;
    while (std::cin >> s) {
        if (s.find('.') != std::string::npos || s.find(',') != std::string::npos) {
            s = s.substr(0, s.length() - 1);
        }
        mp[s]++;
    }
    std::vector<string_cnt> dict;
    for (auto [key, value] : mp) {
        dict.push_back({ key, value });
    }
    std::sort(dict.begin(), dict.end(), [&](string_cnt a, string_cnt b) {
        return (a.second == b.second ? a.first < b.first : a.second > b.second);
    });
    for (auto [s, cnt] : dict) {
        std::cout << s << ' ' << cnt << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}