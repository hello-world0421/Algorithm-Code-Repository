t = int(input())
for _ in range(t):
    n, c, d = map(int, input().split())
    a = list(map(int, input().split()))
    a = sorted(a)
    ans = [a[0] + i * c + j * d for j in range(n) for i in range(n)]
    if a == sorted(ans):
        print("YES")
    else:
        print("NO")
