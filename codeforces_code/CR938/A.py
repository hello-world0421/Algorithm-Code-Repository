t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    if a * 2 <= b:
        print(n * a)
    elif n & 1:
        print(n // 2 * b + a)
    else:
        print(n // 2 * b)
