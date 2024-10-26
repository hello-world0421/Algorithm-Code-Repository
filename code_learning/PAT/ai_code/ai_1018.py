# 初始化玩家和结果记录
player = {'胜': 0, '平': 0, '负': 0}
result = {'C': [0, 0], 'J': [0, 0], 'B': [0, 0]}

# 自定义比较函数
def custom_compare(a, b):
    rules = {
        ('C', 'J'): 1,
        ('J', 'B'): 1,
        ('B', 'C'): 1
    }
    return rules.get((a, b), -1) if a != b else 0

# 读取输入并处理比赛结果
for _ in range(int(input())):
    res_1, res_2 = input().split()
    comparison = custom_compare(res_1, res_2)
    if comparison > 0:
        player['胜'] += 1
        result[res_1][0] += 1
    elif comparison < 0:
        player['负'] += 1
        result[res_2][1] += 1
    else:
        player['平'] += 1

# 输出玩家结果
print(player['胜'], player['平'], player['负'])
print(player['负'], player['平'], player['胜'])

# 计算并输出最佳手势
best_gestrue_win = max(result, key=lambda x: (result[x][0], -ord(x)))
best_gestrue_lose = max(result, key=lambda x: (result[x][1], -ord(x)))
print(best_gestrue_win, best_gestrue_lose)
