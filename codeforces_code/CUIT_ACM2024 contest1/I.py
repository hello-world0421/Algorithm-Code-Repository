positions = [(1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1)]

def find():
    for i in range(n):
        for j in range(m):
            test = 0
            for px, py in positions:
                x, y = i + px, j + py
                if x < 0 or x >= n or y < 0 or y >= m:
                    continue
                elif matrix[x][y] == 0:
                    test += 1
            if test == cnt:
                return True
    return False

n, m = map(int, input().split())
matrix, cnt = [], 0
for _ in range(n):
    row = list(map(int, input().split()))
    cnt += row.count(0)
    matrix.append(row)
print('WIN') if find() else print('LOSE')