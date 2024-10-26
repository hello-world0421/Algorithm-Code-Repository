import string

def fuction(L, N):
    alphabet = string.ascii_lowercase
    base = len(alphabet)
    total_strings = base ** L
    sequences = []

    for i in range(total_strings - N + 1):
        sequence = ''
        temp = i
        for _ in range(L):
            sequence = alphabet[temp % base] + sequence
            temp //= base
        sequences.append(sequence)

    return sequences

L, N = map(int, input().split())
result = fuction(L, N)
print(result[-1])
