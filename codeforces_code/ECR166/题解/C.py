"""
模拟 + 思维题
时间复杂度 O(n + m)
"""
for _ in range(int(input())):
    n, m = map(int, input().split())
    bounds = [n, m]
    a = []
    a.append(list(map(int, input().split())))
    a.append(list(map(int, input().split())))

    # 第一个被录用到次优职业的候选人的索引
    # 该候选人所期望的最优职业
    bad, badType = -1, -1
    cur = [0, 0]
    ans = 0
    types = [-1] * (n + m + 1)
    for i in range(n + m):
        curType = 0 if a[0][i] >= a[1][i] else 1
        if cur[curType] == bounds[curType]:
            curType ^= 1
            if bad == -1:
                bad = i
                badType = curType ^ 1
        types[i] = curType
        ans += a[types[i]][i]
        cur[types[i]] += 1

    res = []
    for i in range(n + m):
        val = ans - a[types[i]][i]
        if bad != -1 and i < bad and types[i] == badType:
            val += a[badType][bad] - a[badType ^ 1][bad] + a[badType ^ 1][n + m]
        else:
            val += a[types[i]][n + m]
        res.append(val)
    res.append(ans)
    print(*res)