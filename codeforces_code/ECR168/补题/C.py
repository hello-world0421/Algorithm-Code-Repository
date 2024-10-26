for _ in range(int(input())):
    n = int(input())
    s = input()
    ans, sta = 0, 0
    for i in range(0, n, 2):
        if sta > 0:
            sta -= 1
        else:
            sta += 1
        ans += sta
        sta += (1 if s[i + 1] == '(' else -1)
        ans += sta
    print(ans)