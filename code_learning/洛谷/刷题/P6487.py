# 二分查找
def bs(n: int):
    l = 0
    r = len(Fibonacci)
    mid, ans = 0, -1
    while l <= r:
        mid = l + ((r - l) >> 1)
        if Fibonacci[mid] <= n:
            ans = Fibonacci[mid]
            l = mid + 1
        else:
            r = mid - 1
    return ans

MAXN, MAXM= 1e15, 101

n= int(input())
Fibonacci = [1, 2]
while Fibonacci[-1] <= (n * 2):
    Fibonacci.append(Fibonacci[-1] + Fibonacci[-2])

ans, find = -1, -1
while n not in (1, 2):
    find = bs(n)
    if n == find:
        ans = find
        break
    else:
        n -= find

print(n) if ans == -1 else print(ans)