#include <bits/stdc++.h>

using namespace std;
const int MAXN = 101;
const double sml = 1e-9;
vector<vector<double>> mat(MAXN, vector<double>(MAXN + 1));

void gauss(int n) {
    for (int i = 1; i <= n; i++) {
        int max = i;
        for (int j = 1; j <= n; j++) {
            if (j < i && abs(mat[j][j]) >= sml)
                continue;
            if (abs(mat[j][i]) > abs(mat[max][i]))
                max = j;
        }
        swap(mat[i], mat[max]);
        if (abs(mat[i][i]) >= sml) {
            double tmp = mat[i][i];
            for (int j = i; j <= n + 1; j++)
                mat[i][j] /= tmp;
            for (int j = 1; j <= n; j++)
                if (i != j) {
                    double rate = mat[j][i] / mat[i][i];
                    for (int k = i; k <= n + 1; k++)
                        mat[j][k] -= mat[i][k] * rate;
                }
        }
    }
}

int main() {
    mat[1][1] = 1;
    mat[1][2] = 2;
    mat[1][3] = -1;
    mat[1][4] = 9;
    mat[2][1] = 2;
    mat[2][2] = -1;
    mat[2][3] = 2;
    mat[2][4] = 7;
    mat[3][1] = 1;
    mat[3][2] = -2;
    mat[3][3] = 2;
    mat[3][4] = 0;
    gauss(3);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++)
            printf("%.2f ", mat[i][j]);
        cout << '\n';
    }

    return 0;
}