# 模拟一遍即可
for _ in range(int(input())):
    n, m = map(int, input().split())
    if n == m == 1:
        input()
        print(-1)
    elif n == 1 and m != 1:
        a = list(map(int, input().split()))
        print(*a[1:], a[0])
    elif m == 1 and n != 1:
        a = []
        for i in range(n):
            a.append(int(input()))
            if i != 0:
                print(a[i])
        print(a[0])
    elif n != 1 and m != 1:
        for i in range(n):
            a = list(map(int, input().split()))
            print(*a[1:], a[0])