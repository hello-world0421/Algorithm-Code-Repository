import random


"""
通过打表找规律之后利用发现的规律简化过程以减少时间复杂度与空间复杂度
时间复杂度为 O(1)
"""
def bash_game_1(n: int, m: int) -> str:
    return '先手' if n % (m + 1) != 0 else '后手'


"""
利用sg定理暴力求解sg值
sg值为其后继节点的sg值的mex值（即所有后继节点sg值中没有出现过的最小自然数）
sg值等于0则是必败态，sg值不等于0则是必胜态
时间复杂度为 O(n * m)
"""
def bash_game_2(n: int, m: int) -> str:
    sg: list[int] = [0] * (n + 1) # sg表
    appear: map[int: bool] = {i : False for i in range(m + 1)} # 维护 sg值有没有出现过，用于求解 mex值
    # 遍历求出所有的 sg值
    for i in range(1, n + 1):
        # 每次计算时清空 appear 数组
        appear = {i : False for i in range(m + 1)}
        # 遍历其所有后继节点，记录出现过的 sg值
        for j in range(1, m + 1):
            if i - j < 0:
                break
            appear[sg[i - j]] = True
        # 求解 mex值，即为当前节点的 sg值
        for j in range(m + 1):
            if not appear[j]:
                sg[i] = j
                break

    # 打表
    # print(f"打印 n = {n}, m = {m} 的sg表")
    # for i in range(n + 1):
    #     print(f"sg({i:03d}) : {sg[i]}")

    # 根据得到的 sg值判断结果
    return '先手' if sg[n] != 0 else '后手'

if __name__ == '__main__':
    """
    对数器的简易版本
    v : 表示各个整型变量的最大可能
    testTimes : 表示测试的次数
    """
    v: int = 1000
    testTimes: int = 10
    print("测试开始：")
    for _ in range(testTimes):
        n: int = random.randint(1, v)
        m: int = random.randint(1, v)
        ans1: str = bash_game_1(n, m)
        ans2: str = bash_game_2(n, m)
        if ans1 != ans2:
            print('出错了！')
            print(f"{n} {m}")
    print("测试结束。")

    n: int = 100
    m: int = 6
    bash_game_2(n, m)