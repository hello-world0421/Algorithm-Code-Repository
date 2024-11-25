import math

def mo_algorithm(arr, queries):
    n = len(arr)
    q = len(queries)
    block_size = int(math.sqrt(n))
    
    # 结果存储
    results = [0] * q

    # 离线排序：按块排序，块内按右端点排序
    queries = sorted(enumerate(queries), key=lambda x: (x[1][0] // block_size, x[1][1]))
    
    # 维护计数和答案
    cnt = [0] * (max(arr) + 1)
    answer = 0

    def add(x, k):
        nonlocal answer
        cnt[x] += 1
        if cnt[x] == k:
            answer += 1
        elif cnt[x] == k + 1:
            answer -= 1

    def remove(x, k):
        nonlocal answer
        if cnt[x] == k:
            answer -= 1
        elif cnt[x] == k + 1:
            answer += 1
        cnt[x] -= 1

    # 初始化指针
    current_l, current_r = 0, -1

    for idx, (l, r, k) in queries:
        # 调整左指针
        while current_l < l:
            remove(arr[current_l], k)
            current_l += 1
        while current_l > l:
            current_l -= 1
            add(arr[current_l], k)
        
        # 调整右指针
        while current_r < r:
            current_r += 1
            add(arr[current_r], k)
        while current_r > r:
            remove(arr[current_r], k)
            current_r -= 1
        
        # 保存结果
        results[idx] = answer

    return results

# 输入处理
n = int(input())
arr = list(map(int, input().split()))
q = int(input())
queries = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(q)]

# 输出结果
answers = mo_algorithm(arr, queries)
for res in answers:
    print(res)
