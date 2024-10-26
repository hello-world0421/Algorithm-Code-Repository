#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e7 + 1;
vector<int> primes;
bitset<N> isPrime, vis;
int sg[N];

void Eratosthenes(int n) {
    isPrime.reset(0), isPrime.reset(1);
    for (int i = 2; i <= n; i++)
        isPrime.set(i);
    for (ll i = 2; i * i <= n; i++) if (isPrime.test(i)) {
        for (int j = i * i; j <= n; j += i)
            isPrime.reset(j);
    }
    for (int i = 2; i <= n; i++) if (isPrime.test(i))
        primes.push_back(i);
}

void solve() {
    int n; cin >> n;
    int a, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans ^= sg[a];
    }
    cout << (ans != 0 ? "Alice\n" : "Bob\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    sg[0] = 0, sg[1] = 1;
    Eratosthenes(1e7);
    for (int i = 1; i < primes.size(); i++) {
        for (int j = 1; primes[i] * j < N; j += 2) {
            if (!vis.test(primes[i] * j)) {
                vis.set(primes[i] * j);
                sg[primes[i] * j] = i + 1;
            }
        }
    }
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}