for _ in range(int(input())):
    a, b, c = map(int, input().split())
    for _ in range(5):
        res = min(a, b, c)
        if a == res:
            a += 1
        elif b == res:
            b += 1
        elif c == res:
            c += 1
    print(a * b * c)