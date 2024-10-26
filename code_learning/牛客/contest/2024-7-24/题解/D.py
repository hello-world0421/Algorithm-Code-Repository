from decimal import Decimal, getcontext
# 设置小数点的位数
getcontext().prec = 20000000
# 设置最大指数
getcontext().Emax = 20000000
# 设置最小指数
getcontext().Emin = 0
t = int(input())
while t:
    a = input()
    b = input()
    c = Decimal(a) * Decimal(b)  
    print(c)
    t -= 1