n, m, k = map(int, input().split())

rank = 0
num = 0
for i in range(1, n + 1):
    for j in range(i, m + 1):
        if (result := i * j) >= num:
            num = result
            if i != j and max(i, j) <= min(n, m):
                rank += 2
            else:
                rank += 1
        if rank >= k:
            break
    if rank >= k:
        break
print(num)
