from decimal import Decimal, getcontext

getcontext().prec = 50

PI = Decimal(3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
)
ans = []
ans1 = Decimal(4e17 + 1)
for _ in range(int(input())):
    P, A = input().split()
    P = Decimal(P)
    A = Decimal(A)
    if (dis := getcontext().abs(P / A - PI)) == ans1:
        if P < ans[0]:
            ans = [P, A]
    elif dis < ans1:
        ans1 = dis
        ans = [P, A]
print(*ans)