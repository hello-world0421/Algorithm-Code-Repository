#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a)
    {
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        {
            printf("Right triangle\n");
        }
        else if (a * a + b * b < c * c || a * a + c * c < b * b || b * b + c * c < a * a)
        {
            printf("Obtuse triangle\n");
        }
        else
        {
            printf("Acute triangle\n");
        }
        if (a == b || a == c || b == c)
        {
            printf("Isosceles triangle\n");
        }
        if (a == b && b == c)
        {
            printf("Equilateral triangle\n");
        }
    }
    else
    {
        printf("Not triangle");
    }

    return 0;
}