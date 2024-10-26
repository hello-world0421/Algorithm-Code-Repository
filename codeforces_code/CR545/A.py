def check(n):
    cnt = [1] * len(t)
    j = 0
    for i in range(1, len(t)):
        if t[i] == t[i - 1]:
            cnt[j] += 1
        else:
            j += 1
        if j != 0 and cnt[j] >= n and cnt[j - 1] >= n:
            return True
    return False

n = int(input())
t = ''.join(input().split())
l, r = 1, n // 2
ans = 0
while (l <= r):
    mid = l + ((r - l) >> 1)
    if check(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1
print(ans * 2)