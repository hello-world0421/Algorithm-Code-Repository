for _ in range(input()):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = 0
    for i in range(len(a)):
        if b[(i + 1) % 3] >= a[i]:
            ans += a[i]
            b[(i + 1) % 3] -= a[i]
            continue
        else:
            ans += b[(i + 1) % 3]
            a[i] -= b[(i + 1) % 3]