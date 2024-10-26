#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;

int bit[MAX_N];  // 树状数组，用于存储区间内的数值和
int fishs[MAX_N];  // 存储原始鱼的大小
int sortedFishs[MAX_N];  // 存储排序后的鱼的大小
int n;  // 鱼的数量

// 计算 x 的二进制表示中最低位的 1 所代表的值
int lowbit(int x) {
    return x & (-x);
}

// 在树状数组中更新第 x 个元素的值
void update(int x, int val) {
    while (x <= n) {
        bit[x] += val;  // 更新树状数组中相应位置的值
        x += lowbit(x);  // 更新下一个需要更新的位置
    }
}

// 查询树状数组中前 x 个元素的和
int query(int x) {
    int res = 0;
    while (x > 0) {
        res += bit[x];  // 累加树状数组中相应位置的值
        x -= lowbit(x);  // 继续向前查询
    }
    return res;
}

int main() {
    cin >> n;  // 输入鱼的数量
    vector<int> uniqueFishs;  // 用于存储去重后的鱼的大小

    // 输入每条鱼的大小，并同时将其存入原始鱼的数组和排序后的鱼的数组中
    for (int i = 1; i <= n; i++) {
        cin >> fishs[i];
        sortedFishs[i] = fishs[i];
    }

    // 对排序后的鱼的数组进行排序，并去重，得到所有的不重复的鱼的大小
    sort(sortedFishs + 1, sortedFishs + n + 1);
    uniqueFishs.assign(sortedFishs + 1, sortedFishs + n + 1);
    uniqueFishs.erase(unique(uniqueFishs.begin(), uniqueFishs.end()), uniqueFishs.end());

    // 将原始鱼的数组中的大小映射到排序后的鱼的数组中的索引，实现离散化
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(uniqueFishs.begin(), uniqueFishs.end(), fishs[i]) - uniqueFishs.begin() + 1;
        fishs[i] = idx;
    }

    // 使用树状数组统计小于当前位置的鱼的数量，并输出结果
    for (int i = 1; i <= n; i++) {
        int num = query(fishs[i] - 1);  // 查询小于当前位置的鱼的数量
        cout << num;  // 输出结果
        if (i != n) {
            cout << ' ';
        }
        update(fishs[i], 1);  // 更新树状数组，将当前位置的鱼的数量加一
    }

    return 0;
}
