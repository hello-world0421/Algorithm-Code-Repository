import math

# 使用 sg 表的值
sg = [0] * 1000
sg[0] = 0
sg[1] = 1
values = [i * i for i in range(1, 100) if i * i <= 100]
for i in range(2, 101):
    visit = [False] * 1000
    for value in values:
        if value <= i:
            visit[sg[i - value]] = True
        else:
            break
    for j in range(1000):
        if not visit[j]:
            sg[i] = j
            break

# 暴力算法：计算数N的输赢状态（0为必败，1为必赢）
def brute_force(N):
    if N == 0:
        return 0
    for x in range(1, int(math.sqrt(N)) + 1):
        if brute_force(N - x * x) == 0:
            return 1
    return 0

# 对数器：比较 sg 表和暴力算法的结果
def verify():
    for i in range(1, 50):
        brute_result = brute_force(i)
        sg_result = 1 if sg[i] != 0 else 0
        if brute_result != sg_result:
            print(f"Mismatch found at N={i}: brute_force={brute_result}, sg_table={sg_result}")
            return False
    print("All results match.")
    return True

# 运行对数器
verify()
