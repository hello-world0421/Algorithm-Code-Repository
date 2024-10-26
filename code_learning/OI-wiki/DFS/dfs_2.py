n = int(input())
used = [False] * (n+1)
def dfs(path):
    if len(path) == n:
        print(''.join(f"{i:5d}" for i in path))
    for i in range(1, n+1):
        if not used[i]:
            path.append(i)
            used[i] = True
            dfs(path)
            used[i] = False
            path.pop()
dfs([])
