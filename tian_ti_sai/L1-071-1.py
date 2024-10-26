# 判断树结构
decision_tree = {
    1: {
        "question": "问题1",
        "yes": 2,
        "no": 3
    },
    2: {
        "question": "问题2",
        "yes": 4,
        "no": 5
    },
    3: {
        "question": "问题3",
        "yes": 6,
        "no": 7
    },
    4: {
        "question": "问题4",
        "yes": 8,
        "no": 9
    },
    # 其他节点...
}

# 从根节点开始遍历判断树
def traverse_decision_tree(tree, answers):
    node = 1  # 从根节点开始
    for answer in answers:
        if answer == "是":
            node = tree[node]["yes"]
        elif answer == "否":
            node = tree[node]["no"]
    return node

# 玩家的一系列回答
player_answers = ["是", "否", "是", "否"]

# 获取玩家得到的结论编号
conclusion_number = traverse_decision_tree(decision_tree, player_answers)
print("玩家得到的结论编号:", conclusion_number)
