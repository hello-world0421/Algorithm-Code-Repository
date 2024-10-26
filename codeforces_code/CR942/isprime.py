from math import sqrt

n = 0
for i in range(2 * 10 ** 6 + 1, 3 * 10 ** 6, 2):
    if n == 100:
        break
    for j in range(2, int(sqrt(i))+1):
        if i % j == 0:
            break
    else:
        print(i)
        n += 1
# for i in range(3, int(sqrt(1399))+1, 2):
#     if 1399 % i == 0:
#         print('n')
#         break
# else:
#     print('y')
    