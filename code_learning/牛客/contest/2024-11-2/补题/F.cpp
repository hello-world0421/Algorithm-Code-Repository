#include <bits/stdc++.h>

const std::vector<int> var = { 1, 7, 17, 31, 49, 71, 97, 127, 161, 199, 241, 287, 337, 391, 449, 511, 577, 647, 721, 799, 881, 967, 1057 };

void solve() {
    int n; char ch; std::cin >> n >> ch;
    int ans, mid, l = 0, r = var.size();
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (var[mid] <= n) {
            ans = mid; l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    ans = (ans << 1) + 1;
    for (int i = 0; i < ans / 2; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < ans - 2 * i; j++) {
            std::cout << ch;
        }
        std::cout << '\n';
    }

    for (int i = 0; i < ans / 2; i++) {
        std::cout << " ";
    }
    std::cout << ch << '\n';

    for (int i = ans / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < ans - 2 * i; j++) {
            std::cout << ch;
        }
        std::cout << '\n';
    }

    std::cout << n - var[ans >> 1] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}