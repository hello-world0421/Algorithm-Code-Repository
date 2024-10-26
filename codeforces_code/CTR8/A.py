for _ in range(int(input())):
    n, k = map(int, input().split())
    if n == k:
        print(*[1] * k)
    elif k == 1:
        print(*range(1, n + 1))
    else:
        print(-1)