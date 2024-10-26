import sys

input = lambda: sys.stdin.readline().rstrip()

# match 函数
def match(x):
    for i in range(1, n + 1):
        if adj[x][i] and not vis[i]:
            vis[i] = True
            if p[i] == 0 or match(p[i]):
                p[i] = x
                return True
    return False

ans = []

# 读入并存取数据
n = int(input())
# 其实 childs 就是一个邻接表
childs = {num: [] for num in range(1, n + 1)}
for i in range(1, n + 1):
    k, *l = map(int, input().split())
    childs[i] = l

# 使用邻接矩阵的二分图匹配
adj = [[False] * (n + 1) for _ in range(n + 1)]
for child in childs.keys():
    for i in childs[child]:
        adj[child][i] = True

# 关键变量
p = [0] * (n + 1)  # 已匹配变量
vis = [False] * (n + 1)  # 标记变量（每次匹配重置）
cnt = 0

# 处理过程
for i in range(1, n + 1):
    vis = [False] * (n + 1)
    if match(i):
        cnt += 1

# 输出结果
if cnt == n:
    ans.append("Yes")
else:
    ans.append("No")
    ans.append(str(n - cnt))
sys.stdout.write('\n'.join(ans))