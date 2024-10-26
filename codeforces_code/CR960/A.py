for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    while len(a) > 0:
        if (num_max := a.count(max(a))) & 1:
            print("YES")
            break
        else:
            for _ in range(num_max):
                a.pop(0)
    else:
        print("NO")
