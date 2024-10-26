#include <bits/stdc++.h>

using namespace std;

bool Isprime(long long num)
{
    if (num == 1)
        return false;
    for (int i = 2; i < int(sqrt(num)) + 1; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool Ispalindrome(long long num)
{
    if (num < 0)
        return false;
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
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a & 1 == 0)
        a++;
    for (long long i = a; i <= b; i += 2)
    {
        if (Ispalindrome(i) && Isprime(i))
        {
            cout << i << '\n';
        }
    }

    return 0;
}