x, y, z, w = map(int, input().split())
if z == w == 0:
    print(-1)
elif z == 0 and w != 0:
    if y % w == 0:
        print(y // w)
    else:
        print(-1)
elif z != 0 and w == 0:
    if x % z == 0:
        print(x // z)
    else:
        print(-1)
elif y % w == x % z == 0 and y // w == x // z:
    print(x // z)
else:
    print(-1)
