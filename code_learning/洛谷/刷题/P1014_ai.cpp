#include <iostream>
#include <cmath>

void solve() {
    int n;
    std::cin >> n;

    // 通过公式反解，快速找到满足条件的 i
    int i = (-1 + std::sqrt(1 + 8.0 * n)) / 2; // 求解 i(i+1)/2 >= n 的近似值
    int res = i * (i + 1) / 2; // 当前三角数

    // 如果 res < n，说明 i 需要加 1
    if (res < n) {
        i++;
        res = i * (i + 1) / 2;
    }

    // 计算 temp：在当前行中的位置
    int temp = n - (i * (i - 1) / 2);

    // 根据奇偶性输出分数
    std::cout << (i & 1 ? i + 1 - temp : temp) << '/'
        << (i & 1 ? temp : i + 1 - temp) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}