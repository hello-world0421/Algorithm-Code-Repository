#include <bits/stdc++.h>

std::vector<int> values(1e6);

void solve() {
    int n; std::cin >> n;

    auto construct_arrays = [&]() {
        std::vector<int> A(values.begin(), values.begin() + n - n / 2);
        std::vector<int> B(values.begin() + n - n / 2, values.begin() + n);

        int xor_A = 0, xor_B = 0;
        for (int a : A) xor_A ^= a;
        for (int b : B) xor_B ^= b;

        if (xor_A != xor_B) {
            B.back() = xor_A ^ xor_B ^ B.back();
        }

        return std::make_pair(A, B);
    };

    auto [A, B] = construct_arrays();
    for (int i = 0; i < n >> 1; i++) {
        std::cout << A[i] << ' ' << B[i] << ' ';
    }
    if (n & 1) std::cout << A[n / 2];
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::iota(values.begin(), values.end(), 0);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);
    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}