#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8;
int matrix[MAXN][MAXN];

int compute(int x, int y, int n)
{
    if (matrix[x][y] == 0)
        return 0;
    int res = 0;
    res += matrix[(x + 1) % n][(y + 1) % n] * matrix[(x + 2) % n][(y + 2) % n] * matrix[(x + 3) % n][(y + 3) % n];
    res += matrix[(x + 1) % n][(y + 2) % n] * matrix[(x + 2) % n][(y + 3) % n] * matrix[(x + 3) % n][(y + 1) % n];
    res += matrix[(x + 1) % n][(y + 3) % n] * matrix[(x + 2) % n][(y + 1) % n] * matrix[(x + 3) % n][(y + 2) % n];
    res -= matrix[(x + 3) % n][(y + 1) % n] * matrix[(x + 2) % n][(y + 2) % n] * matrix[(x + 1) % n][(y + 3) % n];
    res -= matrix[(x + 1) % n][(y + 2) % n] * matrix[(x + 2) % n][(y + 1) % n] * matrix[(x + 3) % n][(y + 3) % n];
    res -= matrix[(x + 3) % n][(y + 2) % n] * matrix[(x + 2) % n][(y + 3) % n] * matrix[(x + 1) % n][(y + 1) % n];
    return res * (int)pow(-1, x + y) * matrix[x][y];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int ans = (n == m ? 0xfffffff : 0);
    n = min(n, m);
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        if (i == 1)
            res = matrix[0][0];
        else if (i == 2)
            res = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        else if (i == 3)
        {
            res += matrix[1 - 1][1 - 1] * matrix[2 - 1][2 - 1] * matrix[3 - 1][3 - 1];
            res += matrix[1 - 1][2 - 1] * matrix[2 - 1][3 - 1] * matrix[3 - 1][1 - 1];
            res += matrix[1 - 1][3 - 1] * matrix[2 - 1][1 - 1] * matrix[3 - 1][2 - 1];
            res -= matrix[3 - 1][1 - 1] * matrix[2 - 1][2 - 1] * matrix[1 - 1][3 - 1];
            res -= matrix[1 - 1][2 - 1] * matrix[2 - 1][1 - 1] * matrix[3 - 1][3 - 1];
            res -= matrix[3 - 1][2 - 1] * matrix[2 - 1][3 - 1] * matrix[1 - 1][1 - 1];
        }
        else if (i == 4)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[0][j] == 0)
                    continue;
                res += compute(0, j, n);
            }
        }
        else if (i == 5)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[0][j] == 0)
                    continue;
                int temp = 0;
                for (int k = (j + 1) % n; k != j;)
                {
                    temp += compute(1, k, n);
                    k = (k + 1) % n;
                }
                res += temp * pow(-1, j) * matrix[0][j];
            }
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';

    return 0;
}