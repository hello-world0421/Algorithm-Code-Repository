#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    auto _sort = [&](std::vector<int>& a, int bucket_size = 100) {
        int w = *std::max_element(a.begin(), a.end());

        int bucket_count = (w / bucket_size) + 1;
        std::vector<std::vector<int>> buckets(bucket_count);

        for (auto x : a) {
            auto index = (x / bucket_size);
            buckets[index].push_back(x);
        }

        int index = 0;
        for (auto& bucket : buckets) {
            std::stable_sort(bucket.begin(), bucket.end());
            for (auto x : bucket) a[index++] = x;
        }
    };

    _sort(a);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}