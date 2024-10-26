for _ in range(int(input())):
    x, y = map(int, input().split())
    x = abs(x)
    print('YES') if -x <= y - x + 1 else print('NO')