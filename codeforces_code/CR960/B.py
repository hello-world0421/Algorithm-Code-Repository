for _ in range(int(input())):
    n, x, y = map(int, input().split())
    a = [1] * (n + 1)

    for i in range(y - 1, -1, -1):
        a[i] = -1 if abs(i - y) & 1 else 1
    for i in range(x + 1, n + 1, 1):
        a[i] = -1 if abs(i - x) & 1 else 1

    print(*a[1:n + 1])