a, b, c = map(int, input().split())
for i in range(20):
    for j in range(20):
            print(f"({i:3d},{j:3d},{i * j:3d}) : {abs(i - a) + abs(j - b) + abs(i * j - c)}")