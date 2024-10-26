a, b = map(int, input().split())
if b == 1:
    print(0)
else:
    for x in range(1, b + 1):
        if x * (a - 1) + 1 >= b:
            print(x)
            break