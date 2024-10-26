#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5 + 1;
constexpr int MAXA = 1e6 + 1;
vector<int> primes;
bitset<MAXA> isprime;

void seive(int n) {
    isprime.set();
    isprime.reset(0), isprime.reset(1);
    for (int i = 2; i <= n; i++) if (isprime.test(i)) {
        primes.push_back(i);
        if (1ll * i * i > n) continue;
        for (int j = i * i; j <= n; j += i)
            isprime.reset(j);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    bitset<78500> se[n];
    vector<int> a(n), result[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
    }

    auto breakdown = [&](int x, int n) {
        for (int i = 2; 1ll * i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                }
                result[x].push_back(i);
            }
        }
        if (n != 1) {
            result[x].push_back(n);
        }
    };
    for (int i = 0; i < n; i++) {
        breakdown(i, a[i]);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    seive(1e6);
    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}