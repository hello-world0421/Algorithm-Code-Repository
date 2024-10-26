# 匹配函数
def find_match(red_index):
    global visited, partner, adjacency_matrix
    for blue_index in range(1, num_blue_items + 1):
        if adjacency_matrix[red_index][blue_index] and not visited[blue_index]:
            visited[blue_index] = True
            if partner[blue_index] == 0 or find_match(partner[blue_index]):
                partner[blue_index] = red_index
                return True
    return False

# 主处理函数
def process_matches():
    global num_red_items, num_blue_items, adjacency_matrix, partner, visited
    num_red_items = int(input())
    num_blue_items = num_red_items
    
    # 创建两个集合的元素列表
    red_items = [tuple(map(int, input().split())) for _ in range(num_red_items)]
    blue_items = [tuple(map(int, input().split())) for _ in range(num_blue_items)]
    
    # 初始化邻接矩阵
    adjacency_matrix = [[False] * (num_blue_items + 1) for _ in range(num_red_items + 1)]
    
    # 填充邻接矩阵
    for red_index in range(num_red_items):
        for blue_index in range(num_blue_items):
            if red_items[red_index][0] < blue_items[blue_index][0] and red_items[red_index][1] < blue_items[blue_index][1]:
                adjacency_matrix[red_index + 1][blue_index + 1] = True
    
    # 初始化匹配结果数组
    partner = [0] * (num_blue_items + 1)
    # 初始化访问标记数组
    visited = [False] * (num_blue_items + 1)
    
    # 计数器
    match_count = 0
    for red_index in range(1, num_red_items + 1):
        visited = [False] * (num_blue_items + 1)
        if find_match(red_index):
            match_count += 1
    print(match_count)

# 主函数
if __name__ == "__main__":
    # 测试用例数量
    test_cases = 1
    # test_cases = int(input())
    while test_cases:
        process_matches()
        test_cases -= 1