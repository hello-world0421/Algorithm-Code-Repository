#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x[7] = { 0, 1, 0, 0, 4, 0, 0 };
    int y[7] = { 0, 0, 2, 3, 0, 5, 6 };

    int a, b; cin >> a >> b;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
                if (x[i] + x[j] + x[k] == a && y[i] + y[j] + y[k] == b) {
                    cout << "Yes\n";
                    return;
                }
    cout << "No\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}