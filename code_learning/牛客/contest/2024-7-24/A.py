n, m, q = map(int, input().split())
a = sorted(list(map(int, input().split())))
for _ in range(m):
    u, v = map(int, input().split())
for _ in range(q):
    k = int(input())
    print(a[k - 1])