#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <random>
#include <cassert>
using namespace std;

struct ComparePairs {
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const
    {
        return lhs.first > rhs.first;
    }
};

// 堆模拟
int waitingTime1(vector<int> &arr, int w)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> heap;
    for (int i = 0; i < arr.size(); i++)
        heap.push({0, arr[i]});
    for (int i = 0; i < w; i++)
    {
        pair<int, int> cur = heap.top();
        heap.pop();
        cur.first += cur.second;
        heap.push(cur);
    }
    return heap.top().first;
}

int check(vector<int> &arr, int time)
{
    int ans = 0;
    for (int x : arr)
        ans += (time / x + 1);
    return ans;
}

// 二分答案法
int waitingTime2(vector<int> &arr, int w)
{
    int min_val = *min_element(arr.begin(), arr.end());
    int ans = 0;
    for (int l = 0, r = min_val * w, mid; l <= r;)
    {
        mid = l + ((r - l) >> 1);
        if (check(arr, mid) >= w + 1)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

// 对数器测试
vector<int> randomArray(int n, int v)
{
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, v);
    for (int i = 0; i < n; i++)
        arr[i] = dis(gen);
    return arr;
}

int main()
{
    cout << "begin:\n";
    // 服务员的最大数量
    int N = 50;
    // 服务员速度的最大值
    int V = 30;
    // 客人的最大数量
    int M = 3000;
    // 测试次数
    int testTime = 20000;
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < 10; i++)
    {
        int n = uniform_int_distribution<>(1, N)(gen);
        vector<int> arr = randomArray(n, V);
        int m = uniform_int_distribution<>(0, M)(gen);
        int ans1 = waitingTime1(arr, m);
        int ans2 = waitingTime2(arr, m);
        assert(ans1 == ans2);
    }
    cout << "end:\n";

    return 0;
}