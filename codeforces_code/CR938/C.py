from collections import deque

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = deque(map(int, input().split()))
    i, j = 0, n - 1
    front = True
    zeros_count = a.count(0)
    while k > 0 and zeros_count != n:
        if front:
            a[i] -= 1
            k -= 1
            if not a[i]:
                i += 1
                zeros_count += 1
        else:
            a[j] -= 1
            k -= 1
            if not a[j]:
                j -= 1
                zeros_count += 1
        front = not front
    print(a.count(0))
