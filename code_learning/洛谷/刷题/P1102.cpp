#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5 + 1;

int n, C, siz;

int tmp[MAXN];

pair<int, int> a[MAXN];

ll l, r, ans, mid, aim, res;

void solve() {
    cin >> n >> C;
    for (int i = 0; i < n; i++) {
        cin >> tmp[i];
    }
    sort(tmp, tmp + n);
    int j = 0;
    for (int i = 0; i < n; j++) {
        a[j].first = tmp[i], a[j].second = 0;
        while (i < n && tmp[i] == a[j].first) {
            a[j].second++; i++;
        }
    }
    siz = j, res = 0;
    for (int i = 0; i < siz; i++) {
        aim = a[i].first - C;
        l = 0, r = siz - 1, ans = -1;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (a[mid].first == aim) {
                ans = mid; break;
            } else if (a[mid].first > aim) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res += (ans == -1 ? 0 : 1ll * a[ans].second * a[i].second);
    }
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}