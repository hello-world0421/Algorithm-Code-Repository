sg = [[[0 for _ in range(6)] for _ in range(6)] for _ in range(6)]
vis = [False for _ in range(500)]

for a in range(1, 6):
    for b in range(max(a, 2), 6):
        for c in range(b, 6):
            if a + b <= c:
                sg[a][b][c] = 0
                continue
            vis = [False] * 500
            for k in range(1, a):
                s = [a - k, b, c]
                s.sort()
                if (s[0] + s[1] > s[2]):
                    vis[sg[a - k][b][c]] = True
            for k in range(1, b):
                s = [a, b - k, c]
                s.sort()
                if (s[0] + s[1] > s[2]):
                    vis[sg[a][b - k][c]] = True
            for k in range(1, c):
                s = [a, b, c - k]
                s.sort()
                if (s[0] + s[1] > s[2]):
                    vis[sg[a][b][c - k]] = True
            for i in range(0, 217):
                if not vis[i]:
                    sg[a][b][c] = i
                    break

for i in range(1, 6):
    for j in range(i, 6):
        for k in range(j, 6):
            if (i + j > k):
                print(f"{i - 1} ^ {j - 1} ^ {k - 1} = {(i - 1) ^ (j - 1) ^ (k - 1)}")
                print(f"sg[{i} {j} {k}] = {sg[i][j][k]}\n")