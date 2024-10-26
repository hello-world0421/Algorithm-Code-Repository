# from functools import reduce


# p = [str(j + 1) for j in range(500)]
# for _ in range(int(input())):
#     n = int(input())
#     s = reduce(lambda x, y: x + y, [i * (2 * i - 1) for i in range(1, n + 1)])
#     m = n * (n + 1) // 2
#     print(' '.join(map(str, [s, m])))
#     a, b, flag = 1, 1, n
#     for i in range(m):
#         print(' '.join([str(a), str(b)] + p[:n]))
#         if b == flag:
#             a += 1
#             b = 1
#             flag -= 1
#         else:
#             b += 1

p = [str(j + 1) for j in range(500)]
for _ in range(int(input())):
    n = int(input())
    s = sum(i * (2 * i - 1) for i in range(1, n + 1))
    m = n * (n + 1) // 2
    print(' '.join(map(str, [s, m])))
    row_index, column_index, remaining = 1, 1, n
    for _ in range(m):
        print(' '.join([str(row_index), str(column_index)] + p[:n]))
        if column_index == remaining:
            row_index += 1
            column_index = 1
            remaining -= 1
        else:
            column_index += 1

# from itertools import chain

# # 定义两个列表
# list1 = [1, 2, 3]
# list2 = ['a', 'b', 'c']

# # 使用chain函数连接两个列表
# merged_list = list(chain(list1, list2))

# print(merged_list)  # 输出：[1, 2, 3, 'a', 'b', 'c']
