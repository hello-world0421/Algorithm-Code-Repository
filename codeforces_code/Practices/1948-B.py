t = int(input())
for _ in range(t):
    input()
    a = input().split()
    for num in a.copy():
        if len(num) > 1:
            i = a.index(num)
            a.remove(num)
            for j in num:
                a.insert(i, j)
                i += 1
    if sorted(a) == a:
        print("YES")
    else:
        print("NO")
