for _ in range(int(input())):
    n = int(input())
    a = input()
    if a.count('111') >= 1:
        print('Yes')
    elif a.count('11') >= 1 and (a[0] == '1' or a[-1] == '1'):
        print('Yes')
    elif a.count('11') >= 2:
        print('Yes')
    elif a[0] == a[-1] == '1':
        print('Yes')
    else:
        print('No')