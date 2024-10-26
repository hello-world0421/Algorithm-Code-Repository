#include <bits/stdc++.h>

constexpr int MAXN = 14;

constexpr double sml = 1e-7;

int n;

double l, r;

double num[MAXN];

double mid, midmid, ans;

double func(double x) {
    double res = 0;
    for (int i = 0; i <= n; i++) {
        res += num[i] * pow(x, i);
    }
    return res;
}

double ssearch(double l, double r) {
    while (l + sml <= r) {
        mid = (l + r) / 2;
        midmid = (mid + r) / 2;
        if (func(mid) > func(midmid))
            ans = mid, r = midmid - sml;
        else
            ans = midmid, l = mid + sml;
    }
    return ans;
}

void solve() {
    std::cin >> n >> l >> r;
    for (int i = n; i >= 0; i--) {
        std::cin >> num[i];
    }
    std::cout << ssearch(l, r) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}