#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 1e4 + 1;

i64 num[MAXN];

constexpr int base = 499;

int n;

int v(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0' + 1;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 11;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 37;
    } else {
        return 0;
    }
}

i64 value(std::string s) {
    i64 val = v(s[0]);
    for (int i = 1; i < s.length(); i++) {
        val = val * base + v(s[i]);
    }
    return val;
}

int cnt() {
    std::sort(num, num + n);
    int ans = 0;
    for (int i = 0; i < n; ans++, i++) {
        while (num[i] == num[i + 1]) { i++; }
    }
    return ans;
}

void solve() {
    std::cin >> n;
    std::string s;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        num[i] = value(s);
    }
    std::cout << cnt() << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}