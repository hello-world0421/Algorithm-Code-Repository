for _ in range(int(input())):
    s = input()
    q = int(input())
    for _ in range(q):
        i, v = input().split()
        i = int(i) - 1
        s = s[:i] + v + s[i + 1:]
        print("YES" if s.find("1100") != -1 else "NO")