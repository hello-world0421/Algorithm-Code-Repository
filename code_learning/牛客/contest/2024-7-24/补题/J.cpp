#include <bits/stdc++.h>
using namespace std;
const long double sml = 1e-9;
const int MAXN = 6;

double gauss(int n, vector<vector<double>> mat)
{
    double det = 1; // 计算行列式部分
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
        // 计算行列式部分
        if (abs(mat[maxi][i]) < sml)
            return 0.0;
        swap(mat[i], mat[maxi]);
        // 计算行列式部分
        if (maxi != i)
            det = -det;
        double tmp = mat[i][i];
        // 计算行列式部分
        det *= tmp;
        for (int j = i; j <= n; j++) // gauss消元时 j <= n + 1
            mat[i][j] /= tmp;
        for (int j = 1; j <= n; j++)
            if (i != j && abs(mat[j][i]) >= sml)
            {
                double rate = mat[j][i];
                for (int k = i; k <= n; k++) // gauss消元时 k <= n + 1
                    mat[j][k] -= mat[i][k] * rate;
            }
    }
    return det;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<double>> mat(n + 1, vector<double>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    int ans = (n == m ? 0xfffffff : 0);
    n = min(n, m);
    for (int i = 1; i <= n; i++)
        ans = min(ans, (int)gauss(i, mat));
    cout << ans;
}