#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 8;
bool mp[MAXN][MAXN];
vector<pair<int, int>> ok;
int mo[6] = { 0, 0, 1, 0, -1, 0 };
int n, m, k;

bool check(int i, int j) {
    if (i >= 3 && mp[i - 1][j] && !mp[i - 2][j]) {
        return true;
    } else if (i <= n - 2 && mp[i + 1][j] && !mp[i + 2][j]) {
        return true;
    } else if (j >= 3 && mp[i][j - 1] && !mp[i][j - 2]) {
        return true;
    } else if (j <= m - 2 && mp[i][j + 1] && !mp[i][j + 2]) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        mp[x][y] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check(i, j)) ok.push_back({ i, j });
        }
    }
    ll ans = INT_MAX;
    for (int i = 0; i < ok.size(); i++) {
        
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}