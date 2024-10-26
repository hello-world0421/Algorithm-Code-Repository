for _ in range(int(input())):
    n = input()
    a = list(map(int, input().split()))
    sum_a = sum(a)
    if (sum_a % 3 == 1):
        for num in a:
            if num % 3 == 1:
                print(1)
                break
        else:
            print(2)
    elif (sum_a % 3 == 2):
        print(1)
    elif (sum_a % 3 == 0):
        print(0)