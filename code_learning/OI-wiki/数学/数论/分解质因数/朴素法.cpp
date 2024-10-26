#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 10001;
vector<int> result1;
vector<int> result2;

// 分解质因数
// 时间复杂度 O(sqrtn)
// 朴素法
void primeBreakDown1(int N) {
    for (int i = 2; 1ll * i * i <= N; i++) {
        if (N % i == 0) {
            while (N % i == 0)
                N /= i;
            result1.push_back(i);
        }
    }
    if (N != 1)
        result1.push_back(N);
}

// 打表优化
// 只适用与 MAXN 比较小的时候
vector<int> primes = {};
bitset<MAXN> isPrime;

void Eratosthenes(int n) {
    isPrime.reset(0), isPrime.reset(1);
    for (int i = 2; i <= n; i++)
        isPrime.set(i);
    for (int i = 2; 1ll * i * i <= n; i++) if (isPrime.test(i)) {
        for (int j = i * i; j <= n; j += i)
            isPrime.reset(j);
    }
    for (int i = 2; i <= n; i++) if (isPrime.test(i))
        primes.push_back(i);
}

void primeBreakDown2(int N) {
    Eratosthenes((int)sqrt(N));
    for (int i = 0; 1ll * primes[i] * primes[i] <= N; i++) {
        if (N % primes[i] == 0) {
            while (N % primes[i] == 0)
                N /= primes[i];
            result2.push_back(primes[i]);
        }
    }
    if (N != 1) {
        result2.push_back(N);
    }
}

int main() {
    /********************
     * 对数器 *
    // cout << "begin:\n";
    // int N = 10000;
    // // 测试次数
    // int testTime = 2000;
    // random_device rd;
    // mt19937 gen(rd());
    // for (int i = 0; i < testTime; i++) {
    //     int n = uniform_int_distribution<>(4, N)(gen);
    //     primeBreakDown1(n);
    //     primeBreakDown2(n);
    //     assert(result1 == result2);
    //     result1.clear();
    //     result2.clear();
    //     primes.clear();
    // }
    // cout << "end:\n";
    ********************/
    primeBreakDown1(999911658);
    for (auto num : result1) {
        cout << num << ' ';
    }

    return 0;
}