from decimal import Decimal, getcontext

getcontext().prec = 20000000
getcontext().Emax = 20000000
getcontext().Emin = 0
for _ in range(int(input())):
    a = input()
    b = input()
    print(Decimal(a) * Decimal(b))