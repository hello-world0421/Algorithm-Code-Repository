#include <bits/stdc++.h>

void solve() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int i1 = s1.find('.'), i2 = s2.find('.');
    std::string int1, int2, flo1, flo2;
    if (i1 != std::string::npos) {
        int1 = s1.substr(0, i1), flo1 = s1.substr(i1 + 1, 6);
        int j = 6 - flo1.length();
        for (int i = 0; i < j; i++) flo1 += "0";
    } else {
        int1 = s1.substr(0, i1), flo1 = "000000";
    }
    if (i2 != std::string::npos) {
        int2 = s2.substr(0, i2), flo2 = s2.substr(i2 + 1, 6);
        int j = 6 - flo2.length();
        for (int i = 0; i < j; i++) flo2 += "0";
    } else {
        int2 = s2.substr(0, i2), flo2 = "000000";
    }
    if (int1 == int2 && flo1 == flo2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}