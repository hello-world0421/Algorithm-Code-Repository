#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n, m, k;
ll a[N];
priority_queue<ll, vector<ll>, greater<ll>> q;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i]);
        if (q.size() > k)
        {
            sum += q.top();
            q.pop();
        }
        if (sum >= m)
        {
            cout << i - 1 << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}