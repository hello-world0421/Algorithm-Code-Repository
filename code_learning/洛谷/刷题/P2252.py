from decimal import Decimal, getcontext

# 设置全局精度
getcontext().prec = 50

a, b = map(int, input().split())
sqrt5 = Decimal(5).sqrt()
phi = (sqrt5 + 1) / 2
min_num, max_num = min(a, b), max(a, b)
print(1 if min_num != int(phi * (max_num - min_num)) else 0)