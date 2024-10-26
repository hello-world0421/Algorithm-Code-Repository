// import sys

// k = int(input())
// a = list(map(int, input().split()))
// n, m, x = map(int, input().split())
// b, ans = [x], 0
// for i in range(1, n+1):
//     b.append(b[i - 1] + a[(i - 1) % k])
//     if b[i-1] % m <= b[i] % m:
//         ans += 1
// sys.stdout.write(str(ans))
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int k, n, m, x;
    vector<long long int> a, b;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    cin >> n >> m >> x;
    int ans = 0;
    b[0] = x;
    for (int i = 1; i < n + 1; i++)
    {
        b[i] = b[i - 1] + a[(i - 1) % k];
        if (b[i - 1] % m <= b[i] % m)
            ans++;
    }
    cout << ans;

    return 0;
}