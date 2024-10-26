import sys


def solve():
    global n
    n = int(input())
    p = [None] + [list(map(int, input().split())) for _ in range(n)]
    q = [None] + [list(map(int, input().split())) for _ in range(n)]

    # 排序
    q = sorted(q[1:], key=lambda x: (x[0], x[1]))
    p = sorted(p[1:], key=lambda x: (x[0], x[1]))

    vis = [False] * (n + 1)
    cnt = 0

    for j in range(1, n + 1):
        mid = -1
        fl = 0
        for i in range(1, n + 1):
            if not vis[i] and p[i][0] < q[j][0] and p[i][1] < q[j][1]:
                fl += 1
                if fl == 1:
                    mid = i
                elif p[i][1] > p[mid][1]:
                    mid = i

        if mid > 0:
            cnt += 1
            vis[mid] = True

    print(cnt)

if __name__ == "__main__":
    solve()