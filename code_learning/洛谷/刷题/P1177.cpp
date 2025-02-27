#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    std::function<void(std::vector<int>&, int, int)> _sort = [&](std::vector<int>& arr, int l, int r) {
        auto merge = [&](int l, int m, int r) {
            std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
            std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

            int i = 0, j = 0, k = l;

            while (i < left.size() && j < right.size()) {
                if (left[i] <= right[j]) arr[k++] = left[i++];
                else arr[k++] = right[j++];
            }

            while (i < left.size()) arr[k++] = left[i++];
            while (j < right.size()) arr[k++] = right[j++];
        };
        int n = arr.size();

        for (int step = 1; step < n; step <<= 1) {
            for (int l = 0; l < n - step; l += (step << 1)) {
                int m = std::min(l + step - 1, n - 1);
                int r = std::min(l + (step << 1) - 1, n - 1);
                merge(l, m, r);
            }
        }
    };

    _sort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}