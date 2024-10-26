#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5 + 1;

int n;

int a[MAXN];

int se[MAXN], siz;

int l, r, ans, mid;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    siz = 0;
    for (int i = 0; i < n; i++, siz++) {
        se[siz] = a[i];
        while (i + 1 < n && a[i + 1] == a[i]) { i++; }
    }
    for (int i = 0; i < siz; i++) {
        cerr << se[i] << ' ';
    }

    auto search = [&](int i, int aim) {
        int l = i, r = siz - 1, ans = siz, mid;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (se[mid] >= aim) {
                ans = mid; r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    };

    auto check = [&](int power) {
        int ans = power;
        int pos = 0;
        while (1) {
            ans++;
            pos = search(pos, a[pos] + power);
            if (pos == siz) { break; }
        }
        return ans;
    };

    l = 0, r = n, ans = -1;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check)
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}