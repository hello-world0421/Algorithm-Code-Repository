#include <bits/stdc++.h>

int WAsolve(int n, std::vector<int>& a) {
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) ok = false;
    }
    if (ok) return 0;
    if (n >= 3) {
        for (int i = 1; i < n - 1; i++) {
            if (a[i] == 0 && a[i - 1] > 0 && a[i + 1] > 0) {
                return 2;
            }
        }
    }
    return 1;
}

int ACsolve(int n, std::vector<int> a) {
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    std::reverse(a.begin(), a.end());
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    std::reverse(a.begin(), a.end());
    if (a.empty()) {
        return 0;
    }
    bool hasZero = false;
    for (auto& x : a) {
        hasZero |= x == 0;
    }
    return hasZero ? 2 : 1;
}

// 函数用于生成随机数据
std::pair<int, std::vector<int>> generate_random_data(int n_min = 1, int n_max = 50, int array_min = 0, int array_max = 100) {
    // 随机生成 n，属于 [1, 50]
    int n = rand() % (n_max - n_min + 1) + n_min;

    // 随机生成一个长度为 n 的数组，元素属于 [0, 100]
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % (array_max - array_min + 1) + array_min;
    }

    return { n, array };
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    // 使用当前时间作为随机种子
    srand(static_cast<unsigned int>(time(0)));

    int tt; std::cin >> tt;
    while (tt--) {
        auto [n, array] = generate_random_data();
        if (ACsolve(n, array) != WAsolve(n, array)) {
            std::cout << "Wrong Answer" << std::endl;
            std::cout << "n = " << n << std::endl;
            std::cout << "array = ";
            for (int i = 0; i < n; ++i) {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
            return 0;
        }
    }

    return 0;
}