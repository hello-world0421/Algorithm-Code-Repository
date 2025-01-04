def anti_hash_hack(n, x=1, cpython=False):
    """
    Input: integer n > 0
    Output: List A of length n
    such that x <= A[i] <= x + 2**(n.bit_length() + 2)
    """
    pow2 = 2**(n.bit_length() + 1) # MODIFIED HERE
    A = [x + pow2]
    i = perturb = x
    while len(A) < n//2:
        A.append(i + pow2)
        if cpython:
            perturb >>= 5
        i = (5 * i + perturb + 1) % pow2
        if not cpython:
            perturb >>= 5
    while len(A) < n:
        A.append(x)
    return A

n = 18100
A = anti_hash_hack(n, 3, False)

while len(A) < 200000:
    A.append(3)
print(1)
print(len(A),len(A))
for x in A:
    print(x,1000)
