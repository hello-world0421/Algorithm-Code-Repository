#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    auto check = [&](vector<ll> s) {
        sort(s.begin(), s.end());
        return s[0] + s[1] > s[2];
    };
    ll a, b, c; cin >> a >> b >> c;
    cout << (check({a * 2, b, c}) || check({a, b * 2, c}) || check({a, b, c * 2}) ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}