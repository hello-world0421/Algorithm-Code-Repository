#include <bits/stdc++.h>

using namespace std;

double solve_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double solve_C(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double a1, a2, a3;
    return solve_distance(x1, y1, x2, y2) +
           solve_distance(x2, y2, x3, y3) +
           solve_distance(x1, y1, x3, y3);
}

int main()
{
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    printf("%.2f", solve_C(x1, y1, x2, y2, x3, y3));

    return 0;
}