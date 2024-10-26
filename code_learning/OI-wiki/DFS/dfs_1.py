# arr = [0] * 103  # arr 用于记录方案

# def dfs(n, m, i, a):
#     if n == 0:
#         print(arr[1:i])
#     if i <= m:
#         for j in range(a, n + 1):
#             arr[i] = j
#             dfs(n - j, m, i + 1, j)  # 请仔细思考该行含义。

# # 主函数
# n, m = map(int, input().split())
# dfs(n, m, 1, 1)
def print_valid_solutions(total, choices, current_index, start_number, solution):
    if total == 0:  # 已经凑出了要求的总数
        print(solution[1:current_index])  # 输出方案
    if current_index <= choices:
        for number in range(start_number, total + 1):  # 从起始数开始尝试
            solution[current_index] = number  # 记录当前选择
            print_valid_solutions(total - number, choices, current_index + 1, number, solution)  # 递归调用

# 主函数
total_sum, num_choices = map(int, input("Enter total sum and number of choices: ").split())
solution_array = [0] * 103  # 用于记录方案
print_valid_solutions(total_sum, num_choices, 1, 1, solution_array)
