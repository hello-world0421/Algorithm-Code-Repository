#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(long long num)
{
    if (num == 2)
        return true;
    if (num < 2 || num % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool IsPalindrome(long long num)
{
    if (num < 0)
        return false; // 负数不是回文数
    int original = num;
    int reversed = 0;

    while (num > 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    if (a <= 2 && b >= 2)
    {
        cout << 2 << '\n';
    }

    for (long long i = max(a, 3LL) + (a % 2 == 0 ? 1 : 0); i <= b; i += 2)
    {
        if (IsPalindrome(i) && IsPrime(i))
        {
            cout << i << '\n';
        }
    }
    return 0;
}
