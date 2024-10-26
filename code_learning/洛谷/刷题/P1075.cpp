#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool ok = false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << n / i;
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << n;
    }

    return 0;
}