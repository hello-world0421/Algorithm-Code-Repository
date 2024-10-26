#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 1e5 + 1;

int n;
std::pair<i64, i64> item[MAXN];
i64 v[MAXN];

// 生成随机数据
void generate_random_data() {
    // 设置随机种子
    std::mt19937 gen(std::time(nullptr));

    std::uniform_int_distribution<int> dist_n(1, 100000);
    // 定义随机数据的规模和范围
    n = dist_n(gen);  // 数据点的数量
    const i64 v_min = 1, v_max = 1000000000000;  // vi的范围
    const int w_min = 1, w_max = 100000;   // w的范围

    // 定义随机数生成器
    std::uniform_int_distribution<i64> dist_v(v_min, v_max);
    std::uniform_int_distribution<int> dist_w(w_min, w_max);

    // 生成随机数据
    i64 sumW = 0;
    for (int i = 1; i <= n; i++) {
        item[i].first = dist_w(gen);
        v[i] = dist_v(gen);
        sumW += item[i].first;
    }

    // 根据sumW调整item[i].second的范围
    for (int i = 1; i <= n; i++) {
        std::uniform_int_distribution<int> dist_second(0, v[i] / sumW);  // 这里假设second应该在0到sumW之间
        item[i].second = dist_second(gen);
    }
}

i64 solve1() {
    std::sort(item + 1, item + n + 1, [](std::pair<i64, i64> a, std::pair<i64, i64> b) {
        return a.second * b.first < b.second * a.first;
    });
    i64 ans = 0, maxW = 0;
    for (int i = 1; i <= n; i++) {
        ans += v[i] - maxW * item[i].second;
        maxW += item[i].first;
    }
    return ans;
}

i64 solve2() {
    i64 maxV = 0, maxW = 0;
    for (int i = 1; i <= n; i++) {
        maxV += v[i], maxW += item[i].first;
    }
    std::sort(item + 1, item + n + 1, [](std::pair<i64, i64> a, std::pair<i64, i64> b) {
        return a.second * b.first > b.second * a.first;
    });
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        maxW -= item[i].first;
        ans += maxW * item[i].second;
    }
    return maxV - ans;
}

int main() {
    int times = 10000;
    while (times--) {
        // 生成随机数据
        generate_random_data();

        if (solve1() != solve2()) {
            std::cout << "Wrong!\n";
            // 输出生成的数据
            std::cout << n << std::endl;
            for (int i = 1; i <= n; i++) {
                std::cout << item[i].first << " " << v[i] << " " << item[i].second << std::endl;
            }
        }
    }

    return 0;
}