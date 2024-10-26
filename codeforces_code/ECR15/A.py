n = int(input())
a = list(map(int, input().split()))

ans, ans1 = 0, 1
for i in range(len(a)):
    if i == 0:
        ans1 += 1
    else:
        if a[i] > a[i - 1]:
            ans1 += 1
        else:
            ans = max(ans, ans1)
            ans1 = 1
ans = max(ans, ans1)
print(ans)