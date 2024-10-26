#include <bits/stdc++.h>
using namespace std;

bool ok = false;
int solve(int n, int m) {
    if (n == 1 && m == 0) {
        return 1;
    }
    if (n == 0 || m == n) {
        return 1;
    }
    if (m == 0) {
        ok = false;
        return solve(n - 1, m) + solve(n - 1, m + 1);
    } else if (m == 1 && !ok) {
        ok = true;
        return solve(n - 1, m) + solve(n - 1, m + 1);
    } else {
        return solve(n - 1, m) + solve(n - 1, m + 1) + solve(n, m - 1);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int n; cin >> n;
    cout << solve(n, 0);

    return 0;
}