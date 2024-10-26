#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e3 + 1;
array<int, MAXN> arr, cnt;
map<int, bool> mp;
array<bool, MAXN> appear = {false};

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (int i = 3; i <= ceil(sqrt(x)); i += 2)
        if (x % i == 0)
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    arr[1] = 1; // 记录第 i 个点涂的颜色
    for (int i = 2; i < MAXN; i++)
    {
        appear.fill(false);
        for (int j = 1; j < i; j++)
            if (isPrime(i ^ j))
                appear[arr[j]] = true;
        for (int j = 1; j < MAXN; j++)
            if (!appear[j])
            {
                arr[i] = j;
                break;
            }
    }
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}