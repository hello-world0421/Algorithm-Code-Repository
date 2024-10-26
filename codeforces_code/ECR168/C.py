for _ in range(int(input())):
    n = int(input())
    s = list(input())
    i, j= 0, 1
    ans = 0
    while i < n and j < n:
        if j <= i:
            j += 1
        elif (s[i] == '_' or s[i] == '(') and (s[j] == ')' or s[j] == '_'):
            ans += j - i
            s[i] = '('
            s[j] = ')'
            i += 1
            j += 1
        elif s[i] == '_' or s[i] == '(':
            j += 1
        else:
            i += 1
    print(ans)