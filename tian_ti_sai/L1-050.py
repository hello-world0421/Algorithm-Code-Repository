import string

def fuction(L, N):
    alphabet = string.ascii_lowercase
    base = len(alphabet)
    total_strings = base ** L
    
    sequence = ""
    temp = total_strings - N
    for _ in range(L):
        sequence = alphabet[temp % base] + sequence
        temp //= base        

    return sequence

L, N = map(int, input().split())
print(fuction(L, N))
