#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e7 + 10;
vector<ll> primes;
bitset<N> isPrime;

void Eratosthenes(int n) {
    isPrime.reset(0), isPrime.reset(1);
    for (ll i = 2; i <= n; i++)
        isPrime.set(i);
    for (ll i = 2; i * i <= n; i++) if (isPrime.test(i)) {
        for (ll j = i * i; j <= n; j += i)
            isPrime.reset(j);
    }
    for (ll i = 3; i <= n; i++) if (isPrime.test(i))
        primes.push_back(i);
}

void solve() {
    int n; cin >> n;
    int a;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            ans ^= 1;
            continue;
        }
        if (a & 1) {
            for (int j = 2; j < primes.size(); j++) {
                if (a % primes[j] == 0) {
                    ans ^= j;
                    break;
                }
            }
        }
    }
    cout << (ans != 0 ? "Alice\n" : "Bob\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    primes.push_back(0), primes.push_back(1);
    Eratosthenes(1e7);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}