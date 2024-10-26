def cul(num):
    for x in range(100):
        for y in range(100):
            if num == x ** 2 - y ** 2:
                return True
    return False

for num in range(-20, 21):
    if cul(num):
        res = True
    else:
        res = False
    print(f"{num:3d}: {res:1d}")
# [-1, 2] 为一个长度为 4 的循环