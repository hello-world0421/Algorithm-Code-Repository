#include <bits/stdc++.h>
using namespace std;

constexpr int N = 7;
double D1, C, D2, P1;
int n, D[N], P[N];

// dis 表示离终点的距离
double compute(double dis, double res, double cost) {
    if (dis <= 0)
        return cost;
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (D[n] - D[i] <= dis && C >= (D[n] - D[i]) / D2) {
            ans = min(ans, compute(D[n] - D[i], 0, cost + (D[i] - (D[n] - dis)) * P[i]));
            cout << ans << ' ';
        }
    }
    return ans;
}

void solve() {
    cin >> D1 >> C >> D2 >> P1 >> n;
    for (int i = 1; i <= n; i++) {
        cin >> D[i] >> P[i];
    }
    D[0] = 0, P[n] = P1;
    D[n] = D1, P[n] = 0;
    cout << compute(D1, 0, 0);
}

int main() {
    // cin.tie(nullptr)->sync_with_stdio(0);

    solve();
    return 0;
}