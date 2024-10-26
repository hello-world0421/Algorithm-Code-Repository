#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 19260817;

int bigModsml(string num, int mod) {
    int ans = 0;
    for (int i = 0; i < num.length(); i++) {
        ans = (ans * 10 + num[i] - '0') % MOD;
    }
    return ans;
}

int d, x, y, tx, ty;

void exgcd(int a, int b) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b);
        tx = x, ty = y;
        x = ty;
        y = tx - ty * (a / b);
    }
}

void solve() {
    string num1, num2; cin >> num1 >> num2;
    int a = bigModsml(num1, MOD), b = bigModsml(num2, MOD);
    exgcd(b, MOD);
    x = (x % MOD + MOD) % MOD;
    cout << 1ll * a * x % MOD << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}