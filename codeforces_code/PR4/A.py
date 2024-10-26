for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(max(a[i] for i in range(0, n, 2)))