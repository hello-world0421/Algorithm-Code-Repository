#include <bits/stdc++.h>

void extractRGB(const std::string& input, int& r, int& g, int& b) {
    char ignore;
    std::stringstream ss(input);
    ss >> ignore >> r >> ignore >> g >> ignore >> b >> ignore;
}

int solution(std::string rgb) {
    rgb = rgb.substr(3);

    int r, g, b;
    extractRGB(rgb, r, g, b);

    return b + (g << 8) + (r << 16);
}

int main() {
    //  You can add more test cases here
    std::cout << (solution("rgb(192, 192, 192)") == 12632256) << std::endl;
    std::cout << (solution("rgb(100, 0, 252)") == 6553852) << std::endl;
    std::cout << (solution("rgb(33, 44, 55)") == 2174007) << std::endl;
    return 0;
}