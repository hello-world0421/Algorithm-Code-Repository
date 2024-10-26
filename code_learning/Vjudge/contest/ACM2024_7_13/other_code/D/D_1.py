import heapq


def solve():
    # 输入处理
    x, y, z, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    # 对数组进行降序排序
    a.sort(reverse=True)
    b.sort(reverse=True)
    c.sort(reverse=True)

    # 初始化优先队列，用于存放当前最大和及对应的索引
    pq = []
    heapq.heappush(pq, (a[0] + b[0] + c[0], 0, 0, 0))
    # 记录已访问过的组合，避免重复计算
    visited = [[[False for _ in range(z+1)] for _ in range(y+1)] for _ in range(x+1)]

    while k:
        # 弹出当前最大和及其索引
        _, xi, yi, zi = heapq.heappop(pq)
        # 若该组合已被访问过，则跳过
        if visited[xi][yi][zi]:
            continue
        visited[xi][yi][zi] = True  # 标记已访问
        print(a[xi] + b[yi] + c[zi])  # 输出当前最大和
        k -= 1

        # 尝试更新组合，向优先队列中加入可能的下一个更大和
        if xi+1 < x:
            heapq.heappush(pq, (a[xi+1] + b[yi] + c[zi], xi+1, yi, zi))
        if yi+1 < y:
            heapq.heappush(pq, (a[xi] + b[yi+1] + c[zi], xi, yi+1, zi))
        if zi+1 < z:
            heapq.heappush(pq, (a[xi] + b[yi] + c[zi+1], xi, yi, zi+1))

def main():
    # 多组测试用例处理
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()