def jie_cheng(n):
    if n == 1:
        return 1
    else:
        return n * jie_cheng(n-1)

a, b = map(int, input().split())
print(jie_cheng(a+b))
