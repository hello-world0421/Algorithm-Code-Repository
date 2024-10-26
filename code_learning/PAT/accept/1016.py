A, D_A, B, D_B = input().split()

n_1, n_2 = A.count(D_A), B.count(D_B)
print(int(D_A * n_1 if n_1 != 0 else '0') + int(D_B * n_2 if n_2 != 0 else '0'))
