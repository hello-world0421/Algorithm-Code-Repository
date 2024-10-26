t = int(input())
for _ in range(t):
    n = int(input())
    num = list(input())
    i, ans = 0, n
    temp = num.copy()
    while temp.count('1') != n:
        if temp[i] == '1':
            i += 1
        if i + ans > n:
            ans -= 1
            i = 0
            temp = num.copy()
        for j in range(i, i + ans):
            if temp[j] == '1':
                temp[j] = '0'
            elif temp[j] == '0':
                temp[j] = '1'
    print(ans)
