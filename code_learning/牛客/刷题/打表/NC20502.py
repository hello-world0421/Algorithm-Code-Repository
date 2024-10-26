a = [0] * 200
a[1] = 1
for i in range(2, 101):
    if i & 1 == 0:
        a[i] = a[i >> 1]
    else:
        a[i] = a[i >> 1] + a[(i >> 1) + 1]
for i in range(0, 101, 4):
    print(f"{i:2d} : {a[i]:2d} : {i:08b}")