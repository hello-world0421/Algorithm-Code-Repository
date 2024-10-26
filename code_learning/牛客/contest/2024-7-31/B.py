ans = 0
for _ in range(int(input())):
    s = map(int, input().split('.'))
    for num in s:
        if num < 0 or num > 255:
            break
    else:
        ans += 1
print(ans)