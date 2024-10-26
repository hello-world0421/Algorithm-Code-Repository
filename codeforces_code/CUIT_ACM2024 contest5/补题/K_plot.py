p = 12
for i in range(1, 51):
    cnt = 0
    for x in range(1, 2 ** p + 1):
        if (i ** x) % (2 ** p) == (x ** i) % (2 ** p):
            cnt += 1
    print(f"{i}的结果为：{cnt}")