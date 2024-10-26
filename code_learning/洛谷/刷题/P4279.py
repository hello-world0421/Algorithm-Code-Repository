from functools import reduce
from operator import xor


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    sum_a = sum(a)
    eor = reduce(xor, a)
    if (sum_a == n):
        print("John" if (n & 1) == 0 else "Brother")
    else:
        print("John" if eor != 0 else "Brother")