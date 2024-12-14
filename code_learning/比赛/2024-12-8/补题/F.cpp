// F题
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string s; std::cin >> s;
    std::vector<int> a(10, 0);
    for (int i = 1; i <= 9; i++) {
        a[i] = std::count(s.begin(), s.end(), i + '0');
    }

    auto check = [&](const std::vector<int> &a) {
        for (int i = 1; i <= 9; i++) {
            if (a[i] >= 2) return true;
            if (a[i] >= 3) return true;
            if (i + 2 <= 9 && a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0) return true;
        }

        return false;
    };

    std::function<bool(std::vector<int>, int, int)> f = [&](std::vector<int> a, int a1, int a2) {
        if (a1 == 4 && a2 == 1) {
            return true;
        }
        
        if (!check(a)) return false;

        bool ok = false;
        for (int i = 1; i <= 9; i++) {
            if (a[i] >= 2) {
                a[i] -= 2;
                ok |= f(a, a1, a2 + 1);
                a[i] += 2;
            }
            if (a[i] >= 3) {
                a[i] -= 3;
                ok |= f(a, a1 + 1, a2);
                a[i] += 3;
            }
            if (i + 2 <= 9 && a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0) {
                a[i]--; a[i + 1]--; a[i + 2]--;
                ok |= f(a, a1 + 1, a2);
                a[i]++; a[i + 1]++; a[i + 2]++;
            }
        }
        return ok;
    };

    bool ok = false;
    for (int i = 1; i <= 9; i++) {
        if (a[i] == 4) {
            continue;
        }

        a[i]++;
        if (f(a, 0, 0)) {
            std::cout << i << ' ';
            ok = true;
        }
        a[i]--;
    }
    if (!ok) {
        std::cout << -1 << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}