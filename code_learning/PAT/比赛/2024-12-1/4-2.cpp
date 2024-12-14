#include <bits/stdc++.h>

void solve() {
    std::string str1 = "jianglyjianlygsialyngilgngljlingianly";
    std::string str2 = "jiangly";
    std::vector<int> dp(str2.size() + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < str1.size(); i++) {
        for (int j = str2.size() - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                dp[j + 1] += dp[j];
            }
        }
    }
    std::cout << dp[str2.size()] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}