for _ in range(int(input())):
    n, k = map(int, input().split())
    dict = {}
    for _ in range(k):
        brand, cost = map(int, input().split())
        dict[brand] = dict.get(brand, 0) + cost
    ans = 0
    for [brand, cost] in sorted(dict.items(), key=lambda a: -a[1]):
        if n == 0:
            break
        ans += cost
        n -= 1
    print(ans)