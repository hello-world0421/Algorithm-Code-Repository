#include <bits/stdc++.h>
using i64 = long long;

const std::string s[] = { "音乐", "剧情", "UI", "美术" };

void solve() {
    int n; std::cin >> n;
    std::vector<i64> aim(4);
    std::vector<std::vector<i64>> a(4, std::vector<i64>(n));
    for (int i = 0; i < 4; i++) {
        std::cin >> aim[i];
    }
    i64 temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++) {
            std::cin >> temp;
            a[j].push_back(temp);
        }
    i64 ans_day = LLONG_MAX, time, value; std::string ans_str = "##";
    for (int i = 0; i < 4; i++) {
        std::sort(a[i].begin(), a[i].end(), std::greater<i64>());
        time = 0, value = 0;
        for (int j = 0; j < n; j++) {
            value += a[i][j];
            time++;
            if (value >= aim[i] || value < 0) {
                if (time < ans_day) {
                    ans_day = time;
                    ans_str = s[i];
                }
                break;
            }
        }
    }
    if (ans_day == LLONG_MAX) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans_str << ' ' << ans_day << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}