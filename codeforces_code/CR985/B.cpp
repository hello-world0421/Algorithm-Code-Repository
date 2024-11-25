#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::string s1, s2; std::cin >> s1 >> s2;
    // for (int i = 0, j = n - 1, k = 0; i <= j && k < n - 1;) {
    //     if (s1[i] != s1[i + 1]) {
    //         s1[i + 1] = s2[k++];
    //     } else if (s1[j] != s1[j - 1]) {
    //         s1[j - 1] = s2[k++];
    //     } else {
    //         std::cout << "NO\n";
    //         return;
    //     }
    // }
    // std::cout << "YES\n";
    std::queue<int> pathes;
    for (int i = 0; i < n - 1; i++) {
        if (s1[i] != s1[i + 1]) {
            pathes.push(i);
        }
    }
    while (!pathes.empty() && k < n - 1) {
        int path = pathes.front(); pathes.pop();
        s1[path] = 
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}