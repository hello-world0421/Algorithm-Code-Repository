for _ in range(int(input())):
    s = input()
    print('A' if s.count('A') > s.count('B') else 'B')