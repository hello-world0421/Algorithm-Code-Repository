#include <bits/stdc++.h>

using namespace std;
// 标定一个极小值作为 0 值，当 double 类型的数值的绝对值小于这个极小值时视为 0
const double EPS = 1e-9;

int main()
{
    // 矩阵的维数
    int n;
    cin >> n;
    // 存储矩阵数据的变量
    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    // 存储行列式的结果
    double det = 1;
    // 最外层的 i 表示列
    for (int i = 0; i < n; i++)
    {
        // 取一列中的最大值
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[k][i]))
                k = j;
        // 如果一列中绝对值最大值都为 0 ，则该列全为 0 ，行列式也为 0
        if (abs(a[k][i]) < EPS)
        {
            det = 0;
            break;
        }
        // 直接交换 i 行与 k 行的所有元素
        swap(a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        // 这里的 i 又变为表示行
        // 整个循环表示将 i 行的一号元素变为 1
        for (int j = i + 1; j < n; j++)
            a[i][j] /= a[i][i];
        // 利用初等行变换进行处理，使得 i 列 i 点均为 0
        for (int j = 0; j < n; j++)
            if (j != i && abs(a[j][i]) > EPS)
                for (int k = i + 1; k < n; k++)
                    a[j][k] -= a[i][k] * a[j][i];
    }
    cout << det;
    return 0;
}