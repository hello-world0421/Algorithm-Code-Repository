for _ in range(int(input())):
    l, r = map(int, input().split())
    cnt = r - l + 1
    ok = False
    if cnt % 3 == 0:
        ok = True
    elif cnt % 3 == 1:
        ok = True if l % 3 == 0 else False
    elif cnt % 3 == 2:
        ok = True if (r + 1) % 3 == 0 else False
    print("YES" if ok else "NO")