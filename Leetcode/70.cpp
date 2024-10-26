#include <bits/stdc++.h>
using namespace std;

int climbStairs1(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int climbStairs2(int n) {
    if (n == 1 || n == 0) return 1;
    int now, last, lastlast;
    lastlast = 1, last = 1;
    for (int i = 2; i <= n; i++) {
        now = last + lastlast;
        lastlast = last, last = now;
    }
    return now;
}

class Matrix {
public:
    std::vector<std::vector<long long>> mat;

    // 构造函数，初始化矩阵大小
    Matrix(int rows, int cols) : mat(rows, std::vector<long long>(cols, 0)) {}

    // 构造函数，从初始值列表初始化矩阵
    Matrix(int rows, int cols, vector<long long> args) : mat(rows, std::vector<long long>(cols, 0)) {
        auto it = args.begin();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = *(it++);
            }
        }
    }

    // 设置矩阵为单位矩阵
    void setIdentity() {
        for (size_t i = 0; i < mat.size(); ++i) {
            mat[i][i] = 1;
        }
    }

    // 矩阵乘法
    Matrix operator*(const Matrix& other) const {
        int r = mat.size(), c = mat[0].size(), o_c = other.mat[0].size();
        Matrix result(r, o_c);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < o_c; ++j) {
                for (int k = 0; k < c; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // 快速幂
    Matrix power(int k) const {
        Matrix result(mat.size(), mat.size());
        result.setIdentity();
        Matrix base(*this);

        while (k > 0) {
            if (k & 1)
                result = result * base;
            base = base * base;
            k >>= 1;
        }
        return result;
    }
};

long long climbStairs3(int n) {
    Matrix mat(1, 2, { 1, 1 }), ans(1, 2), b(2, 2, { 0, 1, 1, 1 });
    ans = mat * b.power(n - 1);
    return ans.mat[0][1];
}

int main() {
    int n = 30;

    std::cout << climbStairs3(n) << '\n';
    std::cout << climbStairs2(n) << '\n';
    std::cout << climbStairs1(n) << '\n';
}