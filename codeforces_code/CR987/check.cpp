#include <bits/stdc++.h>

int solve(int n, std::vector<int>& a) {
    int loop_count = 0;
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] - a[i + 1] == 1) {
                ok = true;
                std::swap(a[i], a[i + 1]);
            }
        }
        if (ok) loop_count++;
    }
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            ans = false; break;
        }
    }
    return loop_count;
}

std::vector<int> generate_random_permutation(int n) {
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1; // 生成1到n的数组
    }
    std::random_device rd;  // 获取随机数种子
    std::mt19937 g(rd());   // 使用Mersenne Twister算法生成随机数
    std::shuffle(a.begin(), a.end(), g); // 随机打乱数组
    return a;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int test_cases = 10000; // 测试用例数量
    int n = 200000; // 数据量大小

    long long total_loop_count = 0;

    for (int tt = 0; tt < test_cases; tt++) {
        std::vector<int> a = generate_random_permutation(n);
        int loop_count = solve(n, a);
        total_loop_count += loop_count;
    }

    double average_loop_count = static_cast<double>(total_loop_count) / test_cases;
    std::cout << "Average loop count: " << average_loop_count << '\n';

    return 0;
}