n = int(input())
parts = list(map(int, input().split()))
print(min(parts), parts.count(min(parts)))
print(max(parts), parts.count(max(parts)))
