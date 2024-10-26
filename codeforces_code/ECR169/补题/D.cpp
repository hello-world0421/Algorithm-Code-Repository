#include <bits/stdc++.h>
using ll = long long;

const char vars[] = { 'B', 'G', 'R', 'Y' };

void solve() {
    int n, q; std::cin >> n >> q;
    std::vector<int> se(n + 1, 0);
    std::string s;
    for (int i = 1; i <= n; i++) {
        std::cin >> s;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                if (s[j] == vars[k]) {
                    se[i] += (1 << k);
                }
            }
        }
    }
    while (q--) {
        int x, y; std::cin >> x >> y;
        int ans = -1;
        if (se[x] & se[y]) {
            ans = std::max(x, y) - std::min(x, y);
        } else if (x < y) {
            for (int i = 1; x + i <= n || x - i > 0; i++) {
                if (x + i < y && se[x] & se[x + i]) {
                    ans = y - x;
                    break;
                } else if (x + i <= n && x + i > y && se[x] & se[x + i]) {
                    ans = ((x + i) << 1) - x - y;
                    break;
                } else if (x - i > 0 && se[x] & se[x - i]) {
                    ans = x + y - ((x - i) << 1);
                    break;
                }
            }
        } else if (x > y) {
            for (int i = 1; x + i <= n || x - i > 0; i++) {
                if (x - i > y && se[x] & se[x - i]) {
                    ans = x - y;
                    break;
                } else if (x - i > 0 && x - i < y && se[x] & se[x - i]) {
                    ans = x + y - ((x - i) << 1);
                    break;
                } else if (x + i <= n && se[x] & se[x + i]) {
                    ans = ((x + i) << 1) - x - y;
                    break;
                }
            }
        }
        std::cout << ans << '\n';
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