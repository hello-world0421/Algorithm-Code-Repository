for _ in range(int(input())):
    n, m, k = map(int, input().split())
    ans = list(range(n, k - 1, -1)) + list(range(m + 1, k)) + list(range(1, m + 1))
    print(*ans)