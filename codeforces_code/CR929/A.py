for _ in range(int(input())):
    n = input()
    print(sum(abs(int(x)) for x in input().split()))