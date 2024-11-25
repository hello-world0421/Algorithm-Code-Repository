import random

def construct_arrays(n: int, m: int):
    A = values[0:n]
    B = values[n:n + m]

    assert set(A).isdisjoint(set(B))

    xor_A = 0
    xor_B = 0
    for a in A:
        xor_A ^= a
    for b in B:
        xor_B ^= b

    if xor_A != xor_B:
        B[-1] = xor_B ^ xor_A ^ B[-1]

    xor_A = 0
    xor_B = 0
    for a in A:
        xor_A ^= a
    for b in B:
        xor_B ^= b

    assert xor_A == xor_B
    return A, B

values = list(range(1000000))
random.shuffle(values)

for _ in range(int(input())):
    n = int(input())
    A, B = construct_arrays(n - n // 2, n // 2)
    for i in range(len(B)):
        print(A[i], B[i], end=' ')
    if n & 1:
        print(A[-1])
    else:
        print()
