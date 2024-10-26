n = int(input())
ans = {}
for i in range(n):
    a, c = map(int, input().split())
    if c not in ans:
        ans[c] = a
    else:
        ans[c] = min(ans[c], a)
print(max(ans.values()))
