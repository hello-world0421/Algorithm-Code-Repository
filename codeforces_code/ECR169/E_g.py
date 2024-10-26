from math import gcd

sg = [0] * 101
for i in range(1, 101):
    vis = [False] * 101
    for j in range(0, i + 1):
        if gcd(i, j) == 1:
            vis[sg[i - j]] = True
    for j in range(0, i + 1):
        if not vis[j]:
            sg[i] = j
            if i & 1:
                print(f"{i}的sg值为: {j}")
            break

# for _ in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split()))
#     ans = 0
#     for num in a:
#         ans ^= sg[num]
#     print("Alice" if ans != 0 else "Bob")