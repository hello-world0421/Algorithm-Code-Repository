def solve()-> None:
    n, m, k = map(int, input().split())
    river = input()
    logs = [i for i in range(n) if river[i] == 'L'] + [n]
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
                print('NO')
                return
    print('YES')


for _ in range(int(input())):
    solve()