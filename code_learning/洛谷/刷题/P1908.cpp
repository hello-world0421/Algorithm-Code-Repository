#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    std::function<i64(std::vector<int>&, int, int)> merge_sort =
        [&](std::vector<int>& arr, int l, int r) -> i64 {
        auto merge = [&](int l, int m, int r) {
            std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
            std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

            int i = 0, j = 0, k = l;
            i64 invCount = 0;

            while (i < left.size() && j < right.size()) {
                if (left[i] <= right[j]) arr[k++] = left[i++];
                else {
                    arr[k++] = right[j++];
                    invCount += m - l - i + 1;
                }
            }

            while (i < left.size()) arr[k++] = left[i++];
            while (j < right.size()) arr[k++] = right[j++];

            return invCount;
        };

        if (l >= r) return 0;

        i64 ans = 0;

        int mid = l + ((r - l) >> 1);
        ans += merge_sort(arr, l, mid);
        ans += merge_sort(arr, mid + 1, r);

        ans += merge(l, mid, r);

        return ans;
    };

    std::cout << merge_sort(a, 0, n - 1) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}