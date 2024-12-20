n = int(input())
a = list(map(int, input().split()))

b, c = 0, 0
for i in range(n):
    if b <= c:
        b += a[i]
    else:
        c += a[i]
print(max(b, c))
