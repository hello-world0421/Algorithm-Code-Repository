n = int(input())
a = list(map(int, input().split()))
ans = [0] * 101
for i in range(1, 101):
    for num in a:
        ans[i] += (num - i) ** 2
print(min(ans[1:]))