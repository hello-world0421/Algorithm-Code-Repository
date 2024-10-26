n, a, b = map(int, input().split())
s = input()
ans, cnt = 0, 0
for ch in s:
    if ch == 'c':
        print('No')
        continue
    elif ch == 'a':
        if ans < a + b:
            print('Yes')
            ans += 1
        else:
            print('No')
    elif ch == 'b':
        if ans < a + b and cnt < b:
            print('Yes')
            ans += 1
            cnt += 1
        else:
            print('No')