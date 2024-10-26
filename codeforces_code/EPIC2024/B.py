for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans, max_num, max_dis = 0, -1, -1
    for num in a:
        if num >= max_num:
            max_num = num
            continue
        ans += (res := max_num - num)
        max_dis = res if res > max_dis else max_dis
    print(0 if ans == 0 else ans + max_dis)