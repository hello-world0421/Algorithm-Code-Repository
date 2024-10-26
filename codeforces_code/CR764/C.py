for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))

    def match(x):
        for i in range(1, n + 1):
            if adj[x][i] and not vis[i]:
                vis[i] = True
                if p[i] == 0 or match(p[i]):
                    p[i] = x
                    return True
        return False
    
    adj = [[False] * (n + 1) for _ in range(n + 1)]

    for i in range(n):
        temp = nums[i]
        for j in range(31):
            if temp in range(1, n + 1):
                adj[i + 1][temp] = True
            if temp == 1:
                break
            temp //= 2
    
    p = [0] * (n + 1)

    cnt = 0
    for i in range(1, n + 1):
        vis = [False] * (n + 1)
        if match(i):
            cnt += 1
    if cnt == n:
        print("YES")
    else:
        print("NO")