/*
数学 (质数判断)
时间复杂度 O(sqrt(n))
*/
#include <bits/stdc++.h>
using namespace std;

bool isprime(int a) {
    if (a <= 2)
        return a == 2;
    if (a % 2 == 0)
        return false;
    for (int i = 3; i * i <= a; i += 2)
        if (a % i == 0)
            return false;
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (isprime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}