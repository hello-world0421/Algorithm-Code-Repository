#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 10001;
vector<int> primes;
// vector<bool> isPrime(N);
// 使用位图优化常数时间与空间
bitset<N> isPrime;

// 时间复杂度 O(n loglogn)
// 经典写法
void Eratosthenes1(int n) {
    isPrime.reset(0), isPrime.reset(1);
    for (int i = 2; i <= n; i++)
        isPrime.set(i);
    for (int i = 2; i <= n; i++) if (isPrime.test(i)) {
        primes.push_back(i);
        if (1ll * i * i > n) continue;
        for (int j = i * i; j <= n; j += i)
            // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
            // 的倍数开始，提高了运行速度
            isPrime.reset(j); // 是 i 的倍数的均不是素数
    }
}

// 时间复杂度 O(n loglogsqrtn) + O(n)
// 平方根优化
void Eratosthenes2(int n) {
    isPrime.reset(0), isPrime.reset(1);
    for (int i = 2; i <= n; i++)
        isPrime.set(i);
    for (int i = 2; i * i <= n; i++) if (isPrime.test(i)) {
        for (int j = i * i; j <= n; j += i)
            isPrime.reset(j);
    }
    for (int i = 2; i <= n; i++) if (isPrime.test(i))
        primes.push_back(i);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    Eratosthenes1(1000);
    cout << primes.size() << endl;
    primes.clear();
    Eratosthenes2(1000);
    cout << primes.size();

    return 0;
}