n, m, q = map(int, input().split())
a = list(map(int, input().split()))
for _ in range(m):
    input()
a.sort()
for _ in range(q):
    i = int(input())
    print(a[i - 1])