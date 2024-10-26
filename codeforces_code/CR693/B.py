for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    n_1, n_2 = a.count(1), a.count(2)
    while n_2 != 0:
        if n_2 == 1:
            n_2 -= 1
            n_1 -= 2
            if n_1 < 0:
                print("NO")
                break
        elif n_2 >= 2:
            n_2 %= 2
    else:
        if n_1 & 1 == 0:
            print("YES")
        else:
            print("NO")
