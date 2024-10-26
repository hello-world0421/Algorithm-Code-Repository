for _ in range(int(input())):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = 0
    # win
    for i in range(3):
        min_num = min(a[i], b[(i + 1) % 3])
        ans += min_num
        a[i] -= min_num
        b[(i + 1) % 3] -= min_num
    # equal
    for i in range(3):
        min_num = min(a[i], b[i])
        a[i] -= min_num
        b[i] -= min_num
    # fail
    ans -= sum(a)

    print(ans)