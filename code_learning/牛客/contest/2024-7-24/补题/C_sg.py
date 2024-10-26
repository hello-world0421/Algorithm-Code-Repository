appear: list[bool] = [False] * 400
sg: list[int] = [0] * 400
for i in range(1, 101):
    appear = [False] * 400
    for j in range(1, i + 1):
        appear[sg[i - j]] = True
    for j in range(1, i + 1):
        for k in range(1, i + 1):
            if j + k >=  i:
                break
            appear[sg[j] ^ sg[k] ^ sg[i - j - k]] = True
    for mex in range(400):
        if not appear[mex]:
            sg[i] = mex
            break

print(sg[0:101])
# 0, 1, 2, 3, 4, 5, 6, 8, 7, 9, 10, 11, 12, 13, 14, 16, 15, 17, 18, 19, 20, 21, 22, 24, 23, 25, 26, 27, 28, 29, 30, 32, 31, 33, 34, 35, 36, 37, 38, 40, 39, 41, 42, 43, 44, 45, 46, 48, 47, 49, 50, 51, 52, 53, 54, 56, 55, 57, 58, 59, 60, 61, 62, 64, 63, 65, 66, 67, 68, 69, 70, 72, 71, 73, 74, 75, 76, 77, 78, 80, 79, 81, 82, 83, 84, 85, 86, 88, 87, 89, 90, 91, 92, 93, 94, 96, 95, 97, 98, 99, 100