for _ in range(int(input())):
    n = int(input())
    grid: list[str] = []
    for _ in range(n):
        grid.append(input())
    for i in range(n - 1):
        if grid[i].count('1') == 0:
            continue
        if grid[i].count('1') == grid[i + 1].count('1'):
            print('SQUARE')
            break
        elif grid[i].count('1') * 2 + 1 == grid[i + 1].count('1') or grid[i].count('1') == grid[i + 1].count('1') * 2 + 1:
            print('TRIANGLE')
            break