n = int(input())

red_points = []
blue_points = []
for _ in range(n):
    red_points.append(tuple(map(int, input().split())))
for _ in range(n):
    blue_points.append(tuple(map(int, input().split())))

