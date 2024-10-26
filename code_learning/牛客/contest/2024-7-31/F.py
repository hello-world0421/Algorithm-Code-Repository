for _ in range(int(input())):
    x, y = map(int, input().split())
    x, y = x, x + y
    ans1, ans2 = 0, 0
    ex = 1
    while ex <= x:
        ans1 += (x // ex)
        ex *= 2
    ex = 1
    while ex <= y:
        ans2 += (y // ex)
        ex *= 2
    print(ans2 - ans1)