from math import sqrt

t = int(input())
map_2 = {}
for i in range(1, t + 1):
    x, y = map(int, input().split())
    map_2[i] = (x, y)
dis = {}
for i in range(1, t + 1):
    for j in range(i + 1, t + 1):
        dis[(i, j)] = sqrt(pow(map_2[i][0] - map_2[j][0], 2) + pow(map_2[i][1] - map_2[j][1], 2))
for i in range(1, t + 1):
    ans = [0, 0]
    for j in set(range(1, t + 1)) - {i}:
        pos = j
        if i > j:
            i, j = j, i
        if dis[(i, j)] > ans[0]:
            ans = [dis[(i, j)], pos]
    print(ans[1])
