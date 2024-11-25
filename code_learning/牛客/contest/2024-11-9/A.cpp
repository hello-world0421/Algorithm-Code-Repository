#include <bits/stdc++.h>

void solve() {
    int a[5];
    double b[5] = { 2.5, 5, 10, 15, 20 };
    for (int i = 0; i < 5; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i <= a[0]; i++)
        for (int j = 0; j <= a[1]; j++)
            for (int k = 0; k <= a[2]; k++)
                for (int l = 0; l <= a[3]; l++)
                    for (int m = 0; m <= a[4]; m++)
                        if (i * b[0] + j * b[1] + k * b[2] + l * b[3] + m * b[4] == 80) {
                            std::cout << "HAPPY";
                            return;
                        }
    std::cout << "SAD";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}