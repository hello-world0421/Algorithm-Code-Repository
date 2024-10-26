for _ in range(int(input())):
    s = input()
    if s.endswith('chimasu'):
        print(s[:-7] + 'tte')
    elif s.endswith('rimasu'):
        print(s[:-6] + 'tte')
    elif s.endswith('mimasu'):
        print(s[:-6] + 'nde')
    elif s.endswith('bimasu'):
        print(s[:-6] + 'nde')
    elif s.endswith('nimasu'):
        print(s[:-6] + 'nde')
    elif s == 'ikimasu':
        print('itte')
    elif s.endswith('kimasu'):
        print(s[:-6] + 'ite')
    elif s.endswith('gimasu'):
        print(s[:-6] + 'ide')
    elif s.endswith('shimasu'):
        print(s[:-7] + 'shite')