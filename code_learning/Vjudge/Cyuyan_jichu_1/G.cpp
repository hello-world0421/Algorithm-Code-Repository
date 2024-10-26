#include <iostream>
using namespace std;

void generateSnakeMatrix(int n)
{
    int matrix[n][n];
    int value = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (value <= n * n)
    {
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = value++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = value++;
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            matrix[bottom][i] = value++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            matrix[i][left] = value++;
        }
        left++;
    }

    // 打印蛇形矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    generateSnakeMatrix(n);
    return 0;
}
