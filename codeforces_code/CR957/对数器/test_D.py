import random


def solve(n: int, m: int, k: int, river: str)-> str:
    logs: list[int] = [i for i in range(n) if river[i] == 'L'] + [n]
    next_log, i = 0, -1
    # 每一循环的目的都是达到下一个木桩
    while i < n - 1:
        if m >= logs[next_log] - i:
            i = logs[next_log]
            next_log += 1
            continue
        i += m
        while i < n and i < logs[next_log]:
            if river[i] != 'C' and k > 0:
                i += 1
                k -= 1
            else:
                return 'NO'
    return 'YES'

def run(n: int, m: int, k: int, A: str) -> str:
    logs = [i for i in range(n) if A[i] == "L"]
    logs.append(n + 1)
    i = -1
    next_log = 0
    while i < n - 1:
        if m >= logs[next_log] - i:
            i = logs[next_log]
        else:
            i += m
            if i > n - 1:
                return 'YES'
            while i < n and i < logs[next_log]:
                if A[i] != "C" and k > 0:
                    i += 1
                    k -= 1
                else:
                    return 'NO'
        next_log += 1
    return 'YES'


import random

def generate_random_string(length: int) -> str:
    # 定义字符集
    characters = ['L', 'C', 'W']
    
    # 使用random.choice从字符集中随机选择字符，重复length次
    random_string = ''.join(random.choice(characters) for _ in range(length))
    
    return random_string

# 调用函数生成长度为10的随机字符串
# random_str = generate_random_string(10)
# print(random_str)


if __name__ == '__main__':
    v: int = 5
    testTimes: int = 10000000
    sum_n: int = 0
    print("测试开始：")
    for _ in range(testTimes):
        n = random.randint(1, v)
        m = random.randint(1, 10)
        k = random.randint(0, v)
        river = generate_random_string(n)
        ans1 = solve(n, m, k, river)
        ans2 = run(n, m, k, river)
        if ans1 != ans2:
            print(f"出错了！\n{n} {m} {k} {river}")
        sum_n += n
        if sum_n > 4000:
            break
    print("测试结束。")