t = int(input())
for _ in range(t):
    n = int(input())
    if n & 1:
        print("NO")
        continue
    else:
        print("YES")
    ans = ""
    for i in range(n//2):
        if not i & 1:
            ans += "AA"
        else:
            ans += "BB"
    print(ans)
    