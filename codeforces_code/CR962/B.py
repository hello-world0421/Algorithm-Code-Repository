for _ in range(int(input())):
    n, k = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append(input())
    for i in range(0, n, k):
        for j in range(0, n, k):
            print(grid[i][j], end='')
        print()