x, y, z, k = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
result = []

for num_1 in a:
    for num_2 in b:
        for num_3 in c:
            result.append(num_1 + num_2 + num_3)
print(*sorted(result, reverse=True)[:k], sep='\n')
