def solve(M, S, T):
    # 每次闪烁法术的消耗和效果
    blink_cost = 10
    blink_distance = 60
    run_speed = 17
    restore_rate = 4  # 每秒恢复魔法点数
    
    time_used = 0
    total_distance = 0
    magic = M
    
    while time_used < T:
        # 如果距离已经能逃脱，提前结束
        if total_distance >= S:
            print("Yes")
            print(time_used)
            return
        
        # 如果魔法值足够，使用闪烁
        if magic >= blink_cost:
            total_distance += blink_distance
            magic -= blink_cost
            time_used += 1
        else:
            # 否则跑步
            total_distance += run_speed
            time_used += 1
        
        # 恢复魔法值（每秒恢复 4 点）
        if magic < blink_cost:
            magic += restore_rate
            if magic > M:
                magic = M  # 魔法值不能超过初始值
    
    # 如果时间用尽，但没有逃脱
    print("No")
    print(total_distance)

# 输入数据
M, S, T = map(int, input().split())
solve(M, S, T)
