import sys

input = lambda: sys.stdin.readline().rstrip()

# match 函数
def match(x):
    for u in adj.keys():
        if vis[u]:
            continue
        vis[u] = True
        if p[u] == 0 or match(p[u]):
            p[u] = x
            return True
    return False

ans = []
# 读入并存取数据
n = int(input())
# 使用邻接表的二分图匹配（ adj 其实就是一个邻接表）
adj = {num: [] for num in range(1, n + 1)}
for i in range(1, n + 1):
    k, *l = map(int, input().split())
    adj[i] = l

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