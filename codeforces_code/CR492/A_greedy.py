cashes = [1, 5, 10, 20, 100]
n = int(input())
ans = 0
for i in range(len(cashes) - 1, -1, -1):
    ans += n // cashes[i]
    n %= cashes[i]
print(ans)
