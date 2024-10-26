def backtrack(choices: list[int], state: int, n: int, res: list[int]) -> int:
    """回溯"""
    # 当爬到第 n 阶时，方案数量加 1
    if state == n:
        res[0] += 1;
    # 遍历所有选择
    for choice in choices:
        # 剪枝：不允许越过第 n 阶
        if state + choice > n:
            continue
        # 尝试：做出选择，更新状态
        backtrack(choices, state + choice, n, res)
        # 回退

def climbing_stairs_backtrack(n : int) -> int:
    """爬楼梯：回溯"""
    choices = [1, 2]
    state = 0
    res = [0]
    backtrack(choices, state, n, res)

    return res[0]

print(climbing_stairs_backtrack(4))
