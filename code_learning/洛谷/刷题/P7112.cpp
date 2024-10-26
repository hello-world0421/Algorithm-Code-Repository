#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double sml = 1e-9;
const int MAXN = 601;

ll gauss(int n, int p, vector<vector<ll>> mat)
{
    ll det = 1;
    for (int i = 1; i <= n; i++)
    {
        int maxi = i;
        for (int j = 1; j <= n; j++)
        {
            if (j < i && abs(mat[j][j]) > sml)
                continue;
            if (abs(mat[j][i]) > abs(mat[maxi][i]))
                maxi = j;
        }
        if (abs(mat[maxi][i]) < sml)
            return 0ll;
        if (maxi != i)
        {
            swap(mat[maxi], mat[i]);
            det = (det * -1 * 1ll + p) % p;
        }
        ll temp = mat[i][i];
        det = det * temp % p;
        for (int j = i; j <= n; j++)
            mat[i][j] /= temp;
        for (int j = 1; j <= n; j++)
        {
            if (i == j || abs(mat[j][i]) < sml)
                continue;
            ll rate = mat[j][i];
            for (int k = j; k <= n; k++)
                mat[j][k] = (mat[j][k] - mat[i][k] * rate % p + p) % p;
        }
    }
    return (det + p) % p;
}

int main()
{
    int n, p;
    cin >> n >> p;
    vector<vector<ll>> mat(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    cout << gauss(n, p, mat);

    return 0;
}