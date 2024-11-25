#include <bits/stdc++.h>

void solve() {
    std::string s[2]; std::cin >> s[0] >> s[1];
    int ind[2];
    std::string sint[2], sfloat[2];
    for (int i = 0; i < 2; i++) {
        ind[i] = s[i].find('.');
        if (ind[i] != std::string::npos) {
            sint[i] = s[i].substr(0, ind[i]), sfloat[i] = s[i].substr(ind[i] + 1, 6);
            int j = 6 - sfloat[i].length();
            for (int k = 0; k < j; k++) sfloat[i] += "0";
        } else {
            sint[i] = s[i], sfloat[i] = "000000";
        }
    }
    std::cout << (sint[0] == sint[1] && sfloat[0] == sfloat[1] ? "YES" : "NO") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}