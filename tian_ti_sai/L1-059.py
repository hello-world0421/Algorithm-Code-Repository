n = int(input())
for i in range(1, n+1):
    s1, s2 = input().split(', ').split()
    if s1[-1][-3:] == s2[-1][-3:-1] == "ong":
        print(', '.join([' '.join(s1), ' '.join(s2)]))
