PI = 3.1415926535
ans = 0xfffff
ans1 = []
for _ in range(int(input())):
    p, a = map(int, input().split())
    if p > 1e9:
        np = p >> 20
        na = a >> 20
    else:
        np, na = p, a
    if abs(np / na - PI) < ans:
        ans1 = [p, a]
print(*ans1)