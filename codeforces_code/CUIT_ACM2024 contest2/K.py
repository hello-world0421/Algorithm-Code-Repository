n, k = map(int, input().split())
ans = []
for i in range(1, n + 1, k):
    ans.append(i)
for i in range(1, n + 1):
    if i not in ans:
        ans.append(i)
print(' '.join(map(str, ans)))