#include <bits/stdc++.h>

int solve(int n, std::vector<int>& a) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    int loop_count = 0, unsorted = n - 1;
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < unsorted; i++) {
            if (a[i + 1] - a[i] > 1) {
                ok = true;
                a[i + 1]--;
                std::swap(a[i], a[i + 1]);
            }
        }
        unsorted--;
        if (ok) loop_count++;
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    return loop_count;
}

std::vector<int> generate_random_permutation(int n) {
    std::vector<int> a(n);
    std::random_device rd;  // 获取随机数种子
    std::mt19937 g(rd());   // 使用Mersenne Twister算法生成随机数
    std::uniform_int_distribution<int> dist(0, 9);
    for (int i = 0; i < n; i++) {
        a[i] = dist(g);
    }
    return a;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int test_cases = 10; // 测试用例数量
    int n = 20; // 数据量大小

    long long total_loop_count = 0;

    for (int tt = 0; tt < test_cases; tt++) {
        std::vector<int> a = generate_random_permutation(n);
        int loop_count = solve(n, a);
        std::cout << "Test case " << tt + 1 << ": " << loop_count << '\n';
        total_loop_count += loop_count;
    }

    double average_loop_count = static_cast<double>(total_loop_count) / test_cases;
    std::cout << "Average loop count: " << average_loop_count << '\n';

    return 0;
}