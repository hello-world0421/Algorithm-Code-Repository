#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int mat1[n + 1][n + 1] = {0}, mat2[m + 1][m + 1] = {0}, mat3[m - n + 2][m - n + 2];
    for (int i = 1; i <= m - n + 1; i++)
        for (int j = 1; j <= m - n + 1; j++)
            mat3[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat1[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat2[i][j];
    for (int i = 1; i <= m - n + 1; i++)
        for (int j = 1; j <= m - n + 1; j++)
            for (int k = i; k <= i + n - 1; k++)
                for (int l = j; l <= j + n - 1; l++)
                    mat3[i][j] += (mat1[k - i + 1][l - j + 1] * mat2[k][l]);
    for (int i = 1; i <= m - n + 1; i++)
    {
        for (int j = 1; j <= m - n + 1; j++)
            cout << mat3[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}