from operator import xor
from functools import reduce


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    eor = reduce(xor, a)
    print("Yes") if eor != 0 else print("No")