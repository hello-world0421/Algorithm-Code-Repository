n = int(input())
a = list(map(int, input().split()))
a.reverse()
ans = 0
for i in range(len(a)):
    if a[i] == 0:
        continue
    if i + 1 < len(a) and a[i] != a[i + 1]:
        ans += 1
    elif i == len(a) - 1:
        ans += 1
print(ans)