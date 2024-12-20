ss = input()
a = []
for i in ss:
    a.append(int(i))
b = a[0]
cnt, ans = 1, 0
for i in range(1, len(a)):
    if a[i] != b:
        cnt += 1
    elif cnt >= 2:
        ans += cnt * (cnt + 1) // 2 - cnt
        cnt = 1
    b = a[i]
if cnt >= 2:
    ans += cnt * (cnt + 1) // 2 - cnt
print(ans)
