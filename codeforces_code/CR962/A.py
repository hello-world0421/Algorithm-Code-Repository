for _ in range(int(input())):
    n = int(input())
    x = n // 4
    y = (n - 4 * x) // 2
    print(x + y)